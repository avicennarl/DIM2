// NOTE: THIS CODE DOES NOT TAKE INTO CONSIDERATION 
//       SWITCH DEBOUNCING, IT WILL BE HANDLED IN LATER VERSION
//     ---- A
//   F/   /B
// G -----
// E/   /C
//  ---- D  o DP
// 7-segment display pins = {A, B, C, D, E, F, G, DP};
const byte displayPins[8] = {2, 3, 4, 5, 6, 7, 8, 9};

const byte keypadRowPins[4] = {10, 11, 12, 13};  // set voltage to Rows
const byte keypadColPins[4] = {A1, A2, A3, A4};  // read from Columns (Analog Input)
//const int DEBOUNCE_TIME = 20; // in ms

//       keyMap[Row][Col]
const char keyMap[4][4] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
const bool commonAnode = false; // set true for common anode 7-segment display, otherwise false

// this array maps keypad characters to their corresponding 7-segment display lights
// each binary digit corresponds to the state of a light segment: (HSB -> LSB) = (A -> DP)
// whereas 1 corresponds to lighting the segment, and 0 to turning it off
// note: add 1 to the value in numberMap[i] if you want to light the Decimal Point (DP)
const byte charMap[15] = {
  0b11111100, // 0
  0b01100000, // 1
  0b11011010, // 2
  0b11110010, // 3
  0b01100110, // 4
  0b10110110, // 5
  0b10111110, // 6
  0b11100000, // 7
  0b11111110, // 8
  0b11100110, // 9
  0b11101110, // A
  0b00111110, // b
  0b00011010, // c
  0b01111010, // d
  0b01101110  // #
};
bool DPon = false;
const int samplingRate = 10; // in ms, the delay between taking inputs

void setup() {
  // initialize all 7-segment display pins as OUTPUT
  // and turn off all segments lights
  for (byte i = 0; i < 8; i++) {
    pinMode(displayPins[i], OUTPUT);
    digitalWrite(displayPins[i], commonAnode);
  }
  // initialize keypad rows pins as output and disable them
  // and columns as input at AnalogInput pins, with pullup resistors enabled
  for (byte i = 0; i < 4; i++) {
    pinMode(keypadRowPins[i], OUTPUT);
    digitalWrite(keypadRowPins[i], HIGH);
    pinMode(keypadColPins[i], INPUT_PULLUP);
  }
}

void loop() {
  // take input from the keypad, and display the same pressed key
  // on the 7-segment display, except for the asterisk '*'
  // which turns on/off the Decimal Point (DP).
  char c = getKeypadInput();
  
  switch (c) {
    case 0:
      break;
    case '*':
      DPon = !DPon;
      if (commonAnode)
        digitalWrite(displayPins[7], !DPon);
      else
        digitalWrite(displayPins[7], DPon);
      break;
    default:
      displayCharOn7Segments(c, DPon);
      break;
  }
  delay(samplingRate);
}

char getKeypadInput() {
  for (byte i = 0; i < 4; i++) {
    digitalWrite(keypadRowPins[i], LOW);
    for (byte j = 0; j < 4; j++) {
      if (digitalRead(keypadColPins[j]) == LOW) {
        digitalWrite(keypadRowPins[i], HIGH);
        return keyMap[i][j];
      }
    }
    digitalWrite(keypadRowPins[i], HIGH);
  }
  return 0; // NULL character
}

// uses 3 global variables: displayPins[8], commonAnode, charMap[15]
void displayCharOn7Segments(char c, bool withDP) {  
  byte mappedChar;
  
  switch (c) {
    case 'A': mappedChar = charMap[10]; break;
    case 'B': mappedChar = charMap[11]; break;
    case 'C': mappedChar = charMap[12]; break;
    case 'D': mappedChar = charMap[13]; break;
    case '#': mappedChar = charMap[14]; break;
    default:  mappedChar = charMap[c - '0']; break; // for c representing numerals
  }
  
  if (withDP) mappedChar++;
  if (commonAnode) mappedChar = ~mappedChar;
  
  for (byte i = 0; i < 8; i++)
    digitalWrite(displayPins[i], bitRead(mappedChar,7-i));
}
