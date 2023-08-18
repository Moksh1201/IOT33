const int LED_PIN = LED_BUILTIN;
const int BUTTON_PIN = 3; // Using digital pin 3 for the button
String name = "";
bool blinking = false;
bool buttonState = false;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  int reading = digitalRead(BUTTON_PIN);
  if (reading != buttonState) {
    delay(50); // Debounce delay
    if (reading != buttonState) {
      buttonState = reading;
      if (buttonState == LOW) {
        toggleBlinking();
        if (blinking) {
          waitForNameInput();
        }
      }
    }
  }

  if (blinking) {
    convertAndBlink();
  } else {
    digitalWrite(LED_PIN, LOW); // Turn off LED
  }
}

void toggleBlinking() {
  blinking = !blinking;
}

void waitForNameInput() {
  if (name.length() == 0) {
    Serial.println("Enter your first name: ");
    while (Serial.available() == 0);
    name = Serial.readStringUntil('\n');
    name.trim();
    if (name.length() > 0) {
      Serial.println("Entered name: " + name);
    }
  }
}

void convertAndBlink() {
  for (int i = 0; i < name.length(); i++) {
    char c = toLowerCase(name[i]);
    if (c >= 'a' && c <= 'z') {
      morseCode(c);
    } else if (c == ' ') {
      delay(3500); // Space between words
    }
  }
}

void morseCode(char letter) {
  const int dotDuration = 400;
  const int dashDuration = 1200;
  const int symbolGap = 100;

  switch (letter) {
    case 'a':
      dot(); 
      ash();
      break;
    case 'b':
      dash(); 
      dot(); 
      dot(); 
      dot();
      break;
    case 'c':
      dash(); 
      dot(); 
      dash(); 
      dot();
      break;
    case 'd':
      dash();
      dot();
      dot();
      break;
    case 'e':
      dot();
      break;
    case 'f':
      dot();
      dot();
      dash();
      dot();
      break;
    case 'g':
      dash();
      dash();
      dot();
      break;
    case 'h':
      dot();
      dot();
      dot();
      dot();
      break;
    case 'i':
      dot();
      dot();
      break;
    case 'j':
      dot();
      dash();
      dash();
      dash();
      break;
    case 'k':
      dash();
      dot();
      dash();
      break;
    case 'l':
      dot();
      dash();
      dot();
      dot();
      break;
    case 'm':
      dash();
      dash();
      break;
    case 'n':
      dash();
      dot();
      break;
    case 'o':
      dash();
      dash();
      dash();
      break;
    case 'p':
      dot();
      dash();
      dash();
      dot();
      break;
    case 'q':
      dash();
      dash();
      dot();
      dash();
      break;
    case 'r':
      dot();
      dash();
      dot();
      break;
    case 's':
      dot();
      dot();
      dot();
      break;
    case 't':
      dash();
      break;
    case 'u':
      dot();
      dot();
      dash();
      break;
    case 'v':
      dot();
      dot();
      dot();
      dash();
      break;
    case 'w':
      dot();
      dash();
      dash();
      break;
    case 'x':
      dash();
      dot();
      dot();
      dash();
      break;
    case 'y':
      dash();
      dot();
      dash();
      dash();
      break;
    case 'z':
      dash();
      dash();
      dot();
      dot();
      break;

  }
  }
}

void dot() {
  digitalWrite(LED_PIN, HIGH);
  delay(400);
  digitalWrite(LED_PIN, LOW);
  delay(100);
}

void dash() {
  digitalWrite(LED_PIN, HIGH);
  delay(1200);
  digitalWrite(LED_PIN, LOW);
  delay(100);
}
