#include <Adafruit_GFX.h>    // Библиотека для работы с графикой
#include <Adafruit_ST7735.h>  // Библиотека для дисплея ST7735S
#include <SPI.h>             // Библиотека для работы с SPI
#include <DHT.h>             // Библиотека для работы с датчиком DHT

#define TFT_CS     6
#define TFT_RST    5
#define TFT_DC     7


Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

#define DHTPIN 4     // Пин, к которому подключен датчик DHT ARDUINO NANO-D4
#define DHTTYPE DHT22   // Тип датчика DHT

DHT dht(DHTPIN, DHTTYPE);



void setup() {

  
  Serial.begin(9600);
  
  // Инициализация дисплея
  tft.initR(INITR_BLACKTAB);
  tft.setRotation(-1);//сдесь можно поворачивать положение экрана(токо в прошивке)-1 и 1 это полжение сверху снизу и наоборот,а 0 в положении телефона(сбоку)крч поиграйтесь 

  dht.begin();
}

void loop() {
  delay(1000);

  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Ошибка при чтении с датчика DHT!");
    return;
  }

  
 


tft.fillScreen(ST7735_WHITE);
  
  tft.print(t);
  tft.println("    c");
  
  tft.setTextColor(ST7735_BLACK);
  tft.setTextSize(5);
  tft.setCursor(1, 30);
delay(3000);

tft.fillScreen(ST7735_WHITE);
  
  tft.print(h);
  
  tft.println("    %");
  
  tft.setTextColor(ST7735_BLACK);
  tft.setTextSize(5);
  tft.setCursor(1, 30);
delay(3000);

      

}