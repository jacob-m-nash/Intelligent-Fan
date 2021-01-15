int switchPin = 13;
int motor = 3;
int switchInput;
int temperatureInputPin = A0;
int LM35Input;
float currentTemperature;
float onTemperature;
float offTemperature;
int waitCounter;
int K = 30;
void setup() {
  Serial.begin(9600);
  pinMode(switchPin, INPUT);
  pinMode(motor, OUTPUT);
  digitalWrite(motor, LOW);
  offTemperature = calcTemperature();
  onTemperature = offTemperature + 10;
  waitCounter = 0;
}

void loop() {
  if ( digitalRead(motor) == LOW) {
    if (digitalRead(switchPin) == 0) {
      digitalWrite(motor, HIGH);
      currentTemperature = calcTemperature();
      float probability = eloProbability(currentTemperature, onTemperature);
      if (onTemperature > currentTemperature) {
        onTemperature = updateEloLose(probability, onTemperature);
      }
      if (onTemperature < currentTemperature) {
        onTemperature = updateEloWin(probability, onTemperature);
      }
    } while (digitalRead(switchPin) == 0);
  }

  if (digitalRead(motor) == HIGH) {
    if (digitalRead(switchPin) == 0) {
      digitalWrite(motor, LOW);
      currentTemperature = calcTemperature();
      float probability = eloProbability(currentTemperature, offTemperature);
      if (offTemperature > currentTemperature) {
        offTemperature = updateEloWin(probability, offTemperature);
      }
      if (onTemperature < currentTemperature) {
        offTemperature = updateEloLose(probability, offTemperature);
      }
    } while (digitalRead(switchPin) == 0);
  }

  delay(1000);
}

float calcTemperature() {
  LM35Input = analogRead(temperatureInputPin);
  return (LM35Input / 1024.0) * 500;
}

float eloProbability(float rating1, float rating2) {
  return 1.0 * 1.0 / (1 + 1.0 *
                      pow(10, 1.0 * (rating1 - rating2) / 400));
}

float updateEloWin(float probability, float temperature) {
  return temperature + K * (1 - probability);
}

float updateEloLose(float probability, float temperature) {
  return temperature + K * (0 - probability);
}
