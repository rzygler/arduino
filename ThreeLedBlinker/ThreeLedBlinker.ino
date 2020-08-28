#define GREEN 7
#define YELLOW 8
#define RED 9

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED as an output.
  pinMode(GREEN, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(RED, OUTPUT);
}

// the loop function runs over and over again forever
void loop(){
  cycleAll(10, 100);
  blinkAll(10, 200, 200);
}

void cycleAll(int numOfCycles, int timeOn)
{
  for (int i = 0; i < numOfCycles; i++)
  {
    turnOn(GREEN);
    delay(timeOn);
    turnOn(YELLOW);
    delay(timeOn);
    turnOn(RED);
    delay(timeOn);
    turnOff(RED);
    delay(timeOn);                     
    turnOff(YELLOW);
    delay(timeOn);
    turnOff(GREEN);
    delay(timeOn * 2); 
  } 
}


void blinkAll(int numOfBlinks, int timeOn, int timeOff)
{
  for (int i = 0; i < numOfBlinks; i++)
  {
    turnOn(GREEN);
    turnOn(YELLOW);
    turnOn(RED);
    delay(timeOn);
    turnOff(GREEN);
    turnOff(RED);
    turnOff(YELLOW);
    delay(timeOff);
  }
}

void turnOn(int color)
{
  digitalWrite(color, HIGH); //turn the LED On by making the voltage HIGH
}

void turnOff(int color)
{
  digitalWrite(color, LOW); // turn the LED Off by making the voltage LOW
}
