int buttonSig; 
int counter = 0;
int goBack = 0;
int moved = 0;
int actuateArmDelay = 8000;
int buttonPin = 9;
const int yellowPin = 13;
const int redPin = 12;
const int bluePin = 11;
const int greenPin = 10;
const int trigPin = 7;
const int echoPin = 8;
unsigned long previousMillis = 0;
long duration;
int distance;


void setup(){
pinMode(buttonPin,INPUT);     //button input
pinMode(yellowPin, OUTPUT);  //yellow
pinMode(redPin, OUTPUT);  //red
pinMode(bluePin, OUTPUT);  //blue
pinMode(greenPin, OUTPUT);  //green
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT);
Serial.begin(9600); // Starts the serial communication
}
void loop(){
unsigned long currentMillis = millis();
buttonSig=digitalRead(buttonPin);
  if(buttonSig==0){
    counter=1;
    YellowOn();    
    }
//else{
//    digitalWrite(13,LOW);
//    }     //this makes the led on only when button is pressed
  measure();
if (counter == 1 ){ //& goBack == 0){
  if (distance > 5){
    GreenOn();
  }
  else{
    GreenOff();
  }  
  if (distance < 5){  
     BlueOn();
      if (currentMillis - previousMillis >= actuateArmDelay){
        previousMillis = currentMillis;
        goBack = 1;
      }
//      else{
//        goBack = 0;
//      }
  }
  else{
    BlueOff();
  }
  if (goBack==1){
    RedOn();
    GreenOff();
  }
}

//Serial.println(distance);
Serial.print("Distance: ");
Serial.println(distance);
}


void measure(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration*0.034/2;
}


void YellowOn(){
  digitalWrite(yellowPin,HIGH);
}
void YellowOff(){
  digitalWrite(yellowPin,LOW);
}
void RedOn(){
  digitalWrite(redPin,HIGH);
}
void RedOff(){
  digitalWrite(redPin,LOW);
}
void BlueOn(){
  digitalWrite(bluePin,HIGH);
}
void BlueOff(){
  digitalWrite(bluePin,LOW);
}
void GreenOn(){
  digitalWrite(greenPin,HIGH);
}
void GreenOff(){
  digitalWrite(greenPin,LOW);
}
