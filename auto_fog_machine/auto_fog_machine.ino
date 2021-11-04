
#define FOG_PIN 5

static const boolean serialPlotting = false;
static const boolean serialLogging = false;

const unsigned int secondsToRun = 10;
const unsigned int secondsToPauseBetweenRuns = 60;


void setup() {
  if (serialLogging)
  {
    Serial.println("In setup");
  }
  Serial.begin( 9600 );
  pinMode(FOG_PIN, OUTPUT);
  digitalWrite(FOG_PIN, LOW);
}

void loop() {
  bool pinOn = false;
  if (serialLogging)
  {
    Serial.println("In loop()");
  }
  
  pinOn = true;
  digitalWrite(FOG_PIN, HIGH);
  if (serialLogging)
  {
    Serial.println("Fogging");
  }
  pauseInSeconds(secondsToRun);
  digitalWrite(FOG_PIN, LOW);

  pauseInSeconds(secondsToPauseBetweenRuns);
}

void pauseInSeconds(unsigned int seconds)
{
    if (serialLogging)
    {
      Serial.println("Pausing...");
    }
    unsigned long millisecondsToWait = seconds * 1000;
    unsigned long startTime = millis();
    unsigned long endTime = startTime;
    
    while ((endTime - startTime) <= millisecondsToWait)
    {
      endTime = millis();
    }
}
