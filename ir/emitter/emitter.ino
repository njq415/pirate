  int bit2 = 0;
  int bit1 = 0;
  int bit0 = 0;
  
void setup() {
  int irpin=13;
  pinMode(irpin,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  burstStart();
  space();
  zero();
  zero();
  zero();
  zero();
  zero();
  one();
  bit2=1;
  one();
  bit1=1;
  zero();
  bit0=0;  
  burstEnd();
  
  Serial.println(bit2);
  Serial.println(bit1);
  Serial.println(bit0);
}

void zero(){
  digitalWrite(irpin,HIGH);
  delayMicroseconds(560);
  digitalWrite(irpin,LOW);
  delayMicroseconds(560);
}
void one(){
  digitalWrite(irpin,HIGH);
  delayMicroseconds(560);
  digitalWrite(irpin,LOW);
  delayMicroseconds(560);
  delayMicroseconds(560);
  delayMicroseconds(560);
}
void burstStart(){
  digitalWrite(irpin,HIGH);
  delayMicroseconds(9000);
}
void space(){
  digitalWrite(irpin,HIGH);
  delayMicroseconds(4500);
}
void burstEnd(){
  digitalWrite(irpin,HIGH);
  delayMicroseconds(560);
}
