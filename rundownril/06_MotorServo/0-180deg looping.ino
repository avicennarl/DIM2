#include <Servo.h>

int posisi = 0;

Servo servo;

void setup()
{
  servo.attach(9);
  Serial.begin(9600);
}

void loop()
{
  for (posisi = 0; posisi <= 180; posisi ++) {

    servo.write(posisi);

    delay(5); // Wait for 15 millisecond(s)
  }
  for (posisi = 180; posisi >= 0; posisi --) {
   
    servo.write(posisi);
    delay(5); // Wait for 15 millisecond(s)
  }
  Serial.println(posisi);
}
