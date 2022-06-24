//Motor Driver Pins
#define M1 6
#define M2 7
#define M3 8
#define M4 9

//Distance Sensor
#define TRIG 11
#define ECHO 10

//Directions
#define FORWARDS 1
#define BACKWARDS 2
#define STOP 0

//Lights
#define GREEN 3
#define RED 4

void setup() {
  Serial.begin(9600);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 if(readDistance() <= 20){
  digitalWrite(GREEN, LOW); 
  digitalWrite(RED, HIGH); 
  Move(STOP);
  delay(2000);
  Move(BACKWARDS);
  delay(2000);
  Move(STOP);
 } else {
  Move(FORWARDS);
  digitalWrite(GREEN, HIGH);
  digitalWrite(RED, LOW); 
 }
 delay(100);
}

void Move(int dir){
  if (dir == FORWARDS){
    digitalWrite(M1, LOW);
    digitalWrite(M2, HIGH);
    digitalWrite(M3, LOW);
    digitalWrite(M4, HIGH);
  } else if (dir == BACKWARDS){
    digitalWrite(M1, HIGH);
    digitalWrite(M2, LOW );
    digitalWrite(M3, HIGH);
    digitalWrite(M4, LOW);
  } else if( dir == STOP){
    digitalWrite(M1, LOW);
    digitalWrite(M2, LOW );
    digitalWrite(M3, LOW);
    digitalWrite(M4, LOW);
  }
}

double readDistance(){
    digitalWrite (TRIG, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG, LOW);

    double duration = pulseIn (ECHO, HIGH);

    double distance = ((duration / 2) * 0.0343);
    Serial.print("The distance is: ");
    Serial.print(distance);
    Serial.println("cm ");

    delay(100);
    return distance;
}
