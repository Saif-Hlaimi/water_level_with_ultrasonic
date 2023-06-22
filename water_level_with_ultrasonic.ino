// Ultrasonic Sensor Pins
int trigPin = 27;
int echoPin = 14;

//here we gonna define two Variables : 
// "empty" is the distance in CM between the ultrasonic and the end of tank when it is empty
int empty = 25;
// "full" is the distance in CM between the ultrasonic and the water surface when the tank is full (it chosen by the user)
int full = 5;


// Variables
long duration;
int distance;
int percentage;

void setup() {
  // Initialize Serial Monitor
  Serial.begin(9600);

  // Configure the sensor pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // Clear the trigger pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Activate the trigger pin
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the echo duration
  duration = pulseIn(echoPin, HIGH);

  // Calculate the distance in centimeters
  distance = duration * 0.034 / 2;
  // Calculate the percentage of water on the tank
  percentage = 100 * (distance - empty) / (full - empty);

  if (distance >= full){
    percentage=100;
  } else if (distance >= empty) {
    percentage = 0;
  }

  // Print the distance on the Serial Monitor
  Serial.print("percentage of water: ");
  Serial.print(percentage);
  Serial.print(" %");


  // Wait for a moment before taking the next measurement
  delay(1000);
}
