int switchPin = 13;
int motor = 3;
int switchInput;
int temperatureInputPin = A0;
int LM35Input;
void setup() {
  Serial.begin(9600);
  pinMode(switchPin,INPUT);
  pinMode(motor, OUTPUT);
  digitalWrite(motor,LOW);
}

void loop() {
  LM35Input= analogRead(temperatureInputPin);
  float temp = calcTemp(LM35Input);
  

  switchInput = digitalRead(switchPin);
  if(switchInput == 0){
    digitalWrite(motor, !digitalRead(motor));
  }
  delay(1000);
}

float calcTemp(int input){
  float res = (input/1024.0) * 500;
  return res;
}
