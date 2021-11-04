
#define MOTOR_PIN 5
#define BRAKE_PIN 6

static const boolean serialPlotting = false;
static const boolean serialLogging = false;

const unsigned int secondsToRunMotor = 19;
const unsigned int secondsToPauseBrake = 2;
const unsigned int secondsToPauseBetweenRuns = 5;

// int ledPin = 13;  // LED on Pin 13 of Arduino
// int pirPin = 7; // Input for HC-S501
// int pirValue; // Place to store read PIR Value
int relayPin = 9;


void setup() {
  Serial.begin( 9600 );
  // pinMode(ledPin, OUTPUT);
  // pinMode(pirPin, INPUT);
  pinMode(MOTOR_PIN, OUTPUT);
  digitalWrite(MOTOR_PIN, LOW);
  pinMode(BRAKE_PIN, OUTPUT);
  digitalWrite(BRAKE_PIN, HIGH);
  
}

void loop() {
  bool pinOn = false;
  Serial.println("Running motor");
  pinOn = true;
  digitalWrite(MOTOR_PIN, HIGH);
  digitalWrite(BRAKE_PIN, LOW);
  pauseInSeconds(secondsToRunMotor);
  if (pinOn)
  {
    Serial.println("Stopping motor");
    digitalWrite(BRAKE_PIN, HIGH);
    pauseInSeconds(secondsToPauseBrake);
    digitalWrite(MOTOR_PIN, LOW);
    
    pinOn = false;
  }
  pauseInSeconds(secondsToPauseBetweenRuns);
  
}

void pauseInSeconds(unsigned int seconds)
{
    unsigned long millisecondsToWait = seconds * 1000;
    unsigned long startTime = millis();
    unsigned long endTime = startTime;
    
    while ((endTime - startTime) <= millisecondsToWait)
    {
      endTime = millis();
    }
}
