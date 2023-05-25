void setup() {
  // running led
  pinMode (2, OUTPUT);
  pinMode (4, OUTPUT);
  pinMode (6, OUTPUT);
  pinMode (8, OUTPUT);
  pinMode (10, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(2, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(6, LOW);
  digitalWrite(8, LOW);
  digitalWrite(10, LOW);  
  delay(1000);

  digitalWrite(2, LOW);
  digitalWrite(4, HIGH);
  delay(1000);

  digitalWrite(4, LOW);
  digitalWrite(6, HIGH);
  delay(1000);

  digitalWrite(6, LOW);
  digitalWrite(8, HIGH); 
  delay(1000);

  digitalWrite(8, LOW);
  digitalWrite(10, HIGH);  
  delay(1000);

  digitalWrite(8, HIGH);
  digitalWrite(10, LOW);  
  delay(1000);  

  digitalWrite(6, HIGH);
  digitalWrite(8, LOW);
  delay(1000);  

  digitalWrite(4, HIGH);
  digitalWrite(6, LOW);
  delay(1000);

  digitalWrite(2, HIGH);
  digitalWrite(4, LOW);
  delay(1000);
}
