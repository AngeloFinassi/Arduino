#include <Servo.h>
#define LDR_1 A0
#define LDR_2 A1
#define LDR_3 A2
#define LDR_4 A3
#define servo_painel 6
#define servo2_painel 5

//Variaveis
int P_Spoint = 90;  //Ângulo de inicial do servo_painel
int P_Spoint2 = 90;

float superior = 0;
float inferior = 0;

float margem_superior = 1023 * 0.7;
float margem_inferior = 1023 * 0.7;

Servo servos_painel;  //Associação da Biblioteca Servo para o servo_painel
Servo servos2_painel;

void setup() {
  //Inicia a comunicação Serial com o Arduino
  Serial.begin(9600);

  //Setagem dos Servos, posição Ângulo inicial
  servos_painel.attach(servo_painel);
  servos2_painel.attach(servo2_painel);

  servos_painel.write(P_Spoint);
  servos2_painel.write(P_Spoint2);
  delay(300);

  //Definição de Entrada para leitura de Tensão dos LDRs
  pinMode(LDR_1, INPUT);
  pinMode(LDR_2, INPUT);
  pinMode(LDR_3, INPUT);
  pinMode(LDR_4, INPUT);
}

void loop() {
  /*Looping While para verificação a diferença de
  incidência luminosa nos LDRs, se não estiverem em seu valor
  mínimo unido a tolerância, esse que é lido com 5 volts*/

  //Chamando a Função para verificar as condições seguintes
  med_Var();

  //Limitador da Posição do Servo, 179º max e 1 min
  if (P_Spoint > 179) P_Spoint = 179;
  if (P_Spoint < 1) P_Spoint = 1;

  if (P_Spoint2 > 179) P_Spoint2 = 179;
  if (P_Spoint2 < 1) P_Spoint2 = 1;

  //Condições Painel
  if (superior >= margem_superior or inferior >= margem_inferior) {
    Serial.println("Parado");
  }

  else {
    if (superior > inferior) {
      P_Spoint = --P_Spoint;
      P_Spoint2 = ++P_Spoint2;
      Serial.println("cima");
    }


    if (inferior > superior) {
      P_Spoint = ++P_Spoint;
      P_Spoint2 = --P_Spoint2;
      Serial.println("baixo");
    }
  }
  servos_painel.write(P_Spoint);
  servos2_painel.write(P_Spoint2);
  delay(80);
}

//Criação de uma função de leitura das tensões dos LDRs
void med_Var() {
  //Variáveis para guardar o valor de tensão lido
  float Tensao1 = analogRead(LDR_1);
  float Tensao2 = analogRead(LDR_2);
  float Tensao3 = analogRead(LDR_3);
  float Tensao4 = analogRead(LDR_4);

  /*Cálculo da intensidade luminosa, superior LDR1 e LDR3, 
  inferior LDR2 e LDR4, junto a adição de uma tolerância em porcentagem*/
  superior = (Tensao1 + Tensao3) / 2;
  inferior = (Tensao2 + Tensao4) / 2;
}
