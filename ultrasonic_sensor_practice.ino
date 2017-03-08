const int trigPin = 9;
const int echoPin = 10;
int ledPin = 12;
long duration;


int lastDist = 0;
int currentDist;

int thresh = 10;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin,HIGH);
  currentDist = duration*0.034/2;

  Serial.print("Distance: ");
  Serial.println(currentDist);
 
 if((currentDist > (lastDist + thresh)) || (currentDist < (lastDist - thresh))){
   digitalWrite(ledPin, HIGH);
   delay(1000);
  }
  else{
    digitalWrite(ledPin, LOW);
  }
  lastDist = currentDist; 
 }
