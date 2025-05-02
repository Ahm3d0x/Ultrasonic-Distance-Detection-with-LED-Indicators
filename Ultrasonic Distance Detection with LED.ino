#define ECHOPIN 9
#define TRIGPIN 10
int lowPins[] = {1, 2};
int highPins[] = {3, 4};

float distance = 0;

void setup() {
  Serial.begin(9600);
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);
  for (int i = 0; i < 2; i++) {
    pinMode(lowPins[i], OUTPUT);
    pinMode(highPins[i], OUTPUT);
  }
}

void loop() {
  digitalWrite(TRIGPIN, LOW); delayMicroseconds(2);
  digitalWrite(TRIGPIN, HIGH); delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);

  distance = pulseIn(ECHOPIN, HIGH) / 58.0;
  Serial.print(distance); Serial.println(" cm");

  if (distance < 15) {
    for (int i = 0; i < 2; i++) {
      digitalWrite(lowPins[i], HIGH);
      digitalWrite(highPins[i], LOW);
    }
  } else {
    for (int i = 0; i < 2; i++) {
      digitalWrite(lowPins[i], LOW);
      digitalWrite(highPins[i], HIGH);
    }
  }

  delay(200);
}


