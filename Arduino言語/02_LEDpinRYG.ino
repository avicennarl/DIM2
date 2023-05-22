int ledPinR=2;
int ledPinY=3;
int ledPinG=4;

void setup()
{
    pinMode(ledPinR,OUTPUT);
    pinMode(ledPinY,OUTPUT);
    pinMode(ledPinG,OUTPUT);//Set the digital 8 port mode, OUTPUT: Output mode
}

void loop()
{  
    digitalWrite(ledPinR,HIGH); //HIGH is set to about 5V PIN8
    delay(1500);               //Set the delay time, 1000 = 1S
    digitalWrite(ledPinR,LOW);  //LOW is set to about 5V PIN8
    delay(1500);
    digitalWrite(ledPinY,HIGH); //HIGH is set to about 5V PIN8
    delay(1500);               //Set the delay time, 1000 = 1S
    digitalWrite(ledPinY,LOW);  //LOW is set to about 5V PIN8
    delay(1500);  
    digitalWrite(ledPinG,HIGH); //HIGH is set to about 5V PIN8
    delay(1500);               //Set the delay time, 1000 = 1S
    digitalWrite(ledPinG,LOW);  //LOW is set to about 5V PIN8
    delay(1500);
    digitalWrite(ledPinY,HIGH); //HIGH is set to about 5V PIN8
    delay(1500);               //Set the delay time, 1000 = 1S
    digitalWrite(ledPinY,LOW);  //LOW is set to about 5V PIN8
    delay(1500); 
    digitalWrite(ledPinR,HIGH); //HIGH is set to about 5V PIN8
    delay(1500);               //Set the delay time, 1000 = 1S
    digitalWrite(ledPinR,LOW);  //LOW is set to about 5V PIN8
    delay(1500);              //Set the delay time, 1000 = 1S
}
