// int ledtest=10;
// int readvalue=0;
// int ledvalue=0;

// void setup(){
//   pinMode(ledtest, OUTPUT);
// }

// void loop(){
//   readvalue= analogRead(A1);
//   ledvalue= map(readvalue, 0, 1024, 0, 255);
//   analogWrite(ledtest, ledvalue);
// }

int led = 9;
int pinPot = A1; 
int nilaiPot = 0;
  
void setup() { 
  pinMode(led,OUTPUT); 
  Serial.begin(9600);
}

void loop() {
  nilaiPot = analogRead(pinPot);
  nilaiPot = map(nilaiPot, 0, 1023, 0, 255);
  analogWrite(led, nilaiPot); Serial.print("nilai ADC: ");
  Serial.println(nilaiPot);
}
