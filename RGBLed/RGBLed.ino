

// define pins
#define BLUE 6
#define GREEN 5
#define RED 3

void setup()
{
  Serial.begin(9600);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);
}

// define variables
int redValue;
int greenValue;
int blueValue;

// main loop
void loop()
{
  //roygbiv();
  cycleAllColors();
}

void roygbiv()
{
  int wait = 400;
  turnRed();
  delay(wait);
  turnOrange();
  delay(wait);
  turnYellow();
  delay(wait);
  turnGreen();
  delay(wait);
  turnBlue();
  delay(wait);
  turnIndigo();
  delay(wait);
  turnViolet();
  delay(wait);
}

void turnRed()
{
  changeColor(225, 0, 0);
}

void turnOrange()
{
  changeColor(225, 30, 0);  
}

void turnYellow()
{
  changeColor(150, 100, 0);  
}

void turnGreen()
{
  changeColor(0, 225, 0);  
}

void turnBlue()
{
  changeColor(0, 0, 225);
}

void turnIndigo()
{
  changeColor(0, 75, 200);
}

void turnViolet()
{
  changeColor(125, 0, 125);
}

void changeColor(int red, int green, int blue)
{
  analogWrite(RED, red);
  analogWrite(GREEN, green);
  analogWrite(BLUE, blue);
}


void cycleAllColors()
{
#define delayTime 10 // fading time between colors

  redValue = 255; // choose a value between 1 and 255 to change the color.
  greenValue = 0;
  blueValue = 0;

  // this is unnecessary as we've either turned on RED in SETUP
  // or in the previous loop ... regardless, this turns RED off
  // analogWrite(RED, 0);
  // delay(1000);

  for (int i = 0; i < 255; i += 1) // fades out red bring green full when i=255
  {
    redValue -= 1;
    greenValue += 1;
    analogWrite(RED, redValue);
    analogWrite(GREEN, greenValue);
    logColors(redValue, greenValue, blueValue );
    delay(delayTime);
  }

  redValue = 0;
  greenValue = 255;
  blueValue = 0;

  for (int i = 0; i < 255; i += 1) // fades out green bring blue full when i=255
  {
    greenValue -= 1;
    blueValue += 1;
    analogWrite(GREEN, greenValue);
    analogWrite(BLUE, blueValue);
    logColors(redValue, greenValue, blueValue );
    delay(delayTime);
  }

  redValue = 0;
  greenValue = 0;
  blueValue = 255;

  for (int i = 0; i < 255; i += 1) // fades out blue bring red full when i=255
  {
    // The following code has been rearranged to match the other two similar sections
    blueValue -= 1;
    redValue += 1;
    analogWrite(BLUE, blueValue);
    analogWrite(RED, redValue);
    logColors(redValue, greenValue, blueValue );
    delay(delayTime);
  }
}

void logColors(int redValue, int greenValue, int blueValue)
{
  Serial.print("RED: ");
  Serial.print(redValue);
  Serial.print(" GREEN: ");
  Serial.print(greenValue );
  Serial.print(" BLUE: ");
  Serial.println(blueValue );
}
