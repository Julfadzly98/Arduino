/*************************************************************
  This is a simple demo of sending and receiving some data.
  Be sure to check out other examples!
 *************************************************************/

// Template ID, Device Name and Auth Token are provided by the Blynk.Cloud
// See the Device Info tab, or Template settings
#define BLYNK_TEMPLATE_ID "TMPLSlZJfak6"
#define BLYNK_DEVICE_NAME "LED1"
#define BLYNK_AUTH_TOKEN "YoxI6xeg9apDCg7r0h4OIDdj-vluFKbG"


// Comment this out to disable prints and save space
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "BwduIIMzHvbR2h3fVhRWgpTQYPLjD3k9";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "smartspace";
char pass[] = "smartspacekk";

BlynkTimer timer;

// This function is called every time the Virtual Pin 0 state changes
BLYNK_WRITE(0) // At global scope (not inside of the function)
{
    int i=param.asInt();
    if (i==1) 
    {
        digitalWrite(13, HIGH);
        digitalWrite(12, LOW);
        Serial.println("test");
    }
    else 
    {
        digitalWrite(12, HIGH);
        digitalWrite(13, LOW);
        Serial.println("ok");
    }
}
//// This function is called every time the device is connected to the Blynk.Cloud
//BLYNK_CONNECTED()
//{
//  // Change Web Link Button message to "Congratulations!"
//  Blynk.setProperty(V3, "offImageUrl", "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations.png");
//  Blynk.setProperty(V3, "onImageUrl",  "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations_pressed.png");
//  Blynk.setProperty(V3, "url", "https://docs.blynk.io/en/getting-started/what-do-i-need-to-blynk/how-quickstart-device-was-made");
//}

// This function sends Arduino's uptime every second to Virtual Pin 2.
//void myTimerEvent()
//{
//  // You can send any value at any time.
//  // Please don't send more that 10 values per second.
//  Blynk.virtualWrite(V2, millis() / 1000);
//}

void setup()
{
  // Debug console
  pinMode(15,OUTPUT);
  Serial.begin(115200);
  delay(100);

  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);

  // Setup a function to be called every second
//  timer.setInterval(1000L, myTimerEvent);
}

void loop()
{
  Blynk.run();
  //timer.run();
  // You can inject your own code or combine it with other sketches.
  // Check other examples on how to communicate with Blynk. Remember
  // to avoid delay() function!
}
