
/////////////////////////////////////////
// Branchements
/////////////////////////////////////////
int triggerPin = 8;
int echoPin = 7;


/////////////////////////////////////////
// Fonction mesurant la distance en cm
/////////////////////////////////////////
long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return 0.01723 * pulseIn(echoPin, HIGH);
}


/////////////////////////////////////
// SETUP
/////////////////////////////////////
void setup()
{
	Serial.begin(9600);
  	Serial.println("Liaison série OK");
}


////////////////////////////////////////
// LOOP
////////////////////////////////////////
void loop()
{
  Serial.println(readUltrasonicDistance(triggerPin,echoPin));
  delay(1000); // Delay a little bit to improve simulation performance
}
