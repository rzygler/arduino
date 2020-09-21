
#include <dht_nonblocking.h>

#define DHT_SENSOR_TYPE DHT_TYPE_11
#define FAN_PIN 5
#define TEMP_ALERT 85

static const int DHT_SENSOR_PIN = 6;
DHT_nonblocking dht_sensor( DHT_SENSOR_PIN, DHT_SENSOR_TYPE );
static const boolean serialPlotting = false;
static const boolean serialLogging = false;


void setup() {
  Serial.begin( 9600 );
  pinMode(FAN_PIN, OUTPUT);
  digitalWrite(FAN_PIN, LOW;
}

void loop() {
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

    if (tempF >= TEMP_ALERT)
    {
      digitalWrite(FAN_PIN, HIGH);
    }
    else
    {
      digitalWrite(FAN_PIN, LOW);
    }
    
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
      Serial.print( "%" );
      Serial.println("");
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
  if( millis( ) - measurement_timestamp > 8000ul )
  {
    if( dht_sensor.measure( temperature, humidity ) == true )
    {
      measurement_timestamp = millis( );
      return( true );
    }
  }

  return( false );
}
