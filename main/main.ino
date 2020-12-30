int switchPin = 13;
int motor = 3;
int switchInput;
void setup() {
  // put your setup code here, to run once:
  pinMode(switchPin,INPUT);
  pinMode(motor, OUTPUT);
  digitalWrite(motor,LOW);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  switchInput = digitalRead(switchPin);
  if(switchInput == 0){
    digitalWrite(motor, !digitalRead(motor));
  }
  delay(100);

}
