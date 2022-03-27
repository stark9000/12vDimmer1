int BUTTON_1 = 3;
int BUTTON_2 = 4;
int PWM_PIN = 5;

int PWM_VALUE = 0;

void setup() {
  //Serial.begin(9600);
  pinMode(BUTTON_1, INPUT_PULLUP);
  pinMode(BUTTON_2, INPUT_PULLUP);
  pinMode(PWM_PIN, OUTPUT);
}

void loop() {
  if (!digitalRead(BUTTON_1)) {
    if (PWM_VALUE < 255) {
      PWM_VALUE = PWM_VALUE + 5 ;
      // Serial.println(PWM_VALUE);
    } else {
      PWM_VALUE = 255;
    }
    analogWrite(PWM_PIN, PWM_VALUE);
    delay(50);
  }
  if (!digitalRead(BUTTON_2)) {
    if (PWM_VALUE > 0) {
      PWM_VALUE = PWM_VALUE - 5 ;
      //Serial.println(PWM_VALUE);
    } else {
      PWM_VALUE = 0;
    }
    analogWrite(PWM_PIN, PWM_VALUE);
    delay(50);
  }

}
