#include <LiquidCrystal.h>
#include <dht_nonblocking.h>
#define DHT_SENSOR_TYPE DHT_TYPE_11

static const int DHT_SENSOR_PIN = 2;
DHT_nonblocking dht_sensor( DHT_SENSOR_PIN, DHT_SENSOR_TYPE );
static const boolean serialPlotting = false;
static const boolean serialLogging = false;


/*
  LiquidCrystal Library - Hello World

 Demonstrates the use of a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD
 and shows the time.

Temp Circuit
See notes for DHT11 set up


  The circuit:
 * LCD RS pin to digital pin 7
 * LCD Enable pin to digital pin 8
 * LCD D4 pin to digital pin 9
 * LCD D5 pin to digital pin 10
 * LCD D6 pin to digital pin 11
 * LCD D7 pin to digital pin 12
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 Library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 Example added 9 Jul 2009
 by Tom Igoe
 Modified 22 Nov 2010
 by Tom Igoe

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystal
 */


// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {

  Serial.begin( 9600 );
  
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  //lcd.print("Hello World!");

  
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  // lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  // lcd.print(millis() / 1000);

  doMeasurements();
}

void doMeasurements()
{
  float temperature;
  float humidity;
  float tempF;
  
  /* Measure temperature and humidity.  If the functions returns
     true, then a measurement is available. */
  if( measure_environment( &temperature, &humidity ) == true )
  {
    tempF = ((temperature * 9) / 5) + 32;

    lcd.setCursor(0,0);
    lcd.print("temp: ");
    lcd.print(tempF);

    lcd.setCursor(0,1);
    lcd.print("humidty: ");
    lcd.print(humidity);
    lcd.print("%");
    
    if (serialPlotting)
    {
      Serial.print( tempF, 1 );
      Serial.print("\t");
      Serial.println( humidity, 1 );
    } 
    if (serialLogging)
    {
      Serial.print( "T = " );
      Serial.print( tempF, 1 );
      Serial.print( " deg. C, H = " );
      Serial.print( humidity, 1 );
      Serial.println( "%" );
    }
  }
  
}


/*
 * Poll for a measurement, keeping the state machine alive.  Returns
 * true if a measurement is available.
 */
static bool measure_environment( float *temperature, float *humidity )
{
  static unsigned long measurement_timestamp = millis( );

  /* Measure once every four seconds. */
  if( millis( ) - measurement_timestamp > 3000ul )
  {
    if( dht_sensor.measure( temperature, humidity ) == true )
    {
      measurement_timestamp = millis( );
      return( true );
    }
  }

  return( false );
}
