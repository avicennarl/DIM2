const int BUTTON1 = 2;
const int BUTTON2 = 3;
const int LED1 = 5;
const int LED2 = 6;
int BUTTONstate1 = 0;
int BUTTONstate2 = 0;

int ledState = LOW;     // the current state of LED
int lastButtonState;    // the previous state of button
int currentButtonState; // the current state of button


void setup()
{
  pinMode(BUTTON1, INPUT);
  pinMode(BUTTON2, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);


  Serial.begin(9600);                // initialize serial
  pinMode(BUTTON2, INPUT_PULLUP); // set arduino pin to input pull-up mode
  pinMode(LED2, OUTPUT);          // set arduino pin to output mode

  currentButtonState = digitalRead(BUTTON2);
}

void loop()
{
  BUTTONstate1 = digitalRead(BUTTON1);
  if (BUTTONstate1 == HIGH)
  {
    digitalWrite(LED1, HIGH);
  } 
  else{
    digitalWrite(LED1, LOW);
  }
  BUTTONstate2 = digitalRead(BUTTON2);
  lastButtonState    = currentButtonState;      // save the last state
  currentButtonState = digitalRead(BUTTON2); // read new state

  if(lastButtonState == HIGH && currentButtonState == LOW) {
    Serial.println("The button is pressed");

    // toggle state of LED
    ledState = !ledState;

    // control LED arccoding to the toggled state
    digitalWrite(LED2, ledState); 
  }
    }
