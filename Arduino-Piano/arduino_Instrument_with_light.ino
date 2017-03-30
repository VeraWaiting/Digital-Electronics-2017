const int kNumPins = 6;
const int inputs[kNumPins] = {A0, A1, A2, A3, A4, A5};
const int leds[kNumPins] = {9, 8, 7, 6, 5, 4};

void setup() {
  Serial.begin(9600);
}

void runLed(int led) {
  analogWrite(led, 255);
  delay(1500);
  analogWrite(led, 0);
}

void printSerial(int index) {
  for (int i = 0; i < kNumPins; ++i) {
    Serial.print(i == index ? "1" : "0");
    Serial.print(",");
  }
  Serial.println();
}

void loop() {
  for (int i = 0; i < kNumPins; ++i) {
    if (analogRead(inputs[i]) < 800) {
      printSerial(i);
      runLed(leds[i]);
    }
  }
}
