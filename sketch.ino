#define LED 11
#define POT A5
#define MAX_FREQ 5000

void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);

  pinMode(POT, INPUT);
}

void loop() {
  double freq = (analogRead(POT) / 1023.0) * MAX_FREQ; // Take percentage of potentiometer value from 0-1 and multiply by MAX_FREQ to get output frequency
  Serial.println(freq);
  if (freq > 0) { // If frequency is 0, set pin to low to avoid divide by zero
    uint32_t microDelay = (1 / freq) * 500000; // Take reciprocal of frequency to get delay in microseconds. Take half of delay, because there are 2 delays per cycle.
    digitalWrite(LED, HIGH);
    delayMicroseconds(microDelay);
    digitalWrite(LED, LOW);
    delayMicroseconds(microDelay);
  } else {
    digitalWrite(LED, LOW);
  }
}
