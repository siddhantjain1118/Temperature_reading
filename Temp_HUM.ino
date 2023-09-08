#define BLYNK_TEMPLATE_ID "TMPL3q9n0LE7E"
#define BLYNK_TEMPLATE_NAME "IOT Sensor"
#define BLYNK_AUTH_TOKEN "La8wZc8wtCSnjFlJ7_S_yn3Qbic3TRao"

#include <DHT.h>
#include <BlynkSimpleEsp8266.h>
#define DHTPIN 4 
#define DHTTYPE DHT11


char auth[]="La8wZc8wtCSnjFlJ7_S_yn3Qbic3TRao";
char ssid[]="Ghost's Galaxy S20 FE 5G";
char pass[]="19944811420";
DHT dht(DHTPIN,DHTTYPE);
void setup() {
  Serial.begin(9600);
  Serial.println("DHT TEST Successful!");
  Blynk.begin(auth,ssid,pass);//for IOT conections to Blynk 
  Serial.print("Blynk Connected Successfully");
  dht.begin();

}

void loop() {
  float h=dht.readHumidity();
  float t=dht.readTemperature();
  float f=dht.readTemperature(true);
  if(isnan(h)||isnan(t)||isnan(f))
  {Serial.println("Something is not working properly");
  return;}
  Serial.print("Humidity:");
  Serial.print(h);
  Serial.print("%");
  Serial.print("  ");
  Serial.print("Temperature:");
  Serial.print(t);
  Serial.println("°C");
  Blynk.virtualWrite(V0,t);
  Blynk.virtualWrite(V1,h);
  delay(2000);
}