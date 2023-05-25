#include <Servo.h>

// Constants
#define BUTTON 2
#define SERVO 9
#define ANGLE_OPEN 0;
#define ANGLE_CLOSED 180;

// Variable declaration
int buttonState;
int angle;
bool locked;
bool held;
Servo servo;

void setup() // Setup
{
  // Variable starting values
  locked = false;
  held = false;
  angle = 0;

  // Pin modes
  pinMode(BUTTON, INPUT);
  pinMode(SERVO, OUTPUT);

  // Attach servo
  servo.attach(SERVO);

}


void loop() // Loop
{
  // Read button state
  buttonState = digitalRead(BUTTON);

  // Toggle locked if button pressed
  if (buttonState == HIGH) {
    // Prevent the button triggering multiple times when held
    while (!held) {
      locked = !locked;
      held = true;
    }
  } else {
    held = false;
  }

  // Check locked for which angle to put
  if (locked) {
    angle = ANGLE_CLOSED;
  }
  else {
    angle = ANGLE_OPEN;
  }

  // Write angle
  servo.write(angle);
}
