#define LDR_1 A0
#define LDR_2 A1
#define LDR_3 A2
#define LDR_4 A3

float superior = 0;
float inferior = 0;

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(LDR_1, INPUT);
  pinMode(LDR_2, INPUT);
  pinMode(LDR_3, INPUT);
  pinMode(LDR_4, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  float Tensao1 = analogRead(LDR_1);
  float Tensao2 = analogRead(LDR_2);
  float Tensao3 = analogRead(LDR_3);
  float Tensao4 = analogRead(LDR_4);

  Serial.println(Tensao1);
  Serial.println(Tensao2);

  /*Cálculo da intensidade luminosa, superior LDR1 e LDR3, 
  inferior LDR2 e LDR4, junto a adição de uma tolerância em porcentagem*/
  superior = (Tensao1 + Tensao3) / 2;
  inferior = (Tensao2 + Tensao4) / 2;
  delay(20);
}
