#include <U8x8lib.h>

#include <DHT.h>
#include <Grove_Temperature_And_Humidity_Sensor.h>

U8X8_SSD1306_128X64_ALT0_HW_I2C u8x8(/* reset=*/ U8X8_PIN_NONE);

DHT dht(3, DHT11);

void setup() {
dht.begin();
u8x8.begin();
u8x8.setFlipMode(1);
u8x8.clear();
pinMode (4, OUTPUT);
}
void loop() {
u8x8.setFont(u8x8_font_chroma48medium8_r);
u8x8.setCursor(0, 0);

float temp = dht.readTemperature();
float humidity = dht.readHumidity();

u8x8.println("Temperature: ");
u8x8.println((temp * 9/5) + 32);
u8x8.println("Humidity: ");
u8x8.print(humidity);
u8x8.print("%");

if(humidity > 60){
digitalWrite(4, HIGH);
tone(5,1000,100);
}
else{
digitalWrite(4, LOW);
}


//noTone(5);
}
