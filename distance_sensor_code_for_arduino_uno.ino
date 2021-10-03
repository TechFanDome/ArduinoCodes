int trigPin = 12;
int echoPin = 7;

int distance;
long duration;
void setup() {
  Serial.begin(9600);  Serial.println("COMMUNICATION PROCESS STARTED");

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}


void loop() {

 digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration*0.034/2;

  Serial.println(distance);
       delay(2000);
       






}
