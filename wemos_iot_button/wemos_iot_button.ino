/*
 * Basic IO
 * Use a pushbutton to toggle the onboard LED.
 *
 * If you do not have the 1 Button Shield, add a pushbutton or switch between D3 and GND
 */


#include <ESP8266WiFi.h>
#include <WiFiClient.h>

#include <HttpClient.h>



// Existing WiFi network
char* ssid     = "";
char* password = "";
char* ssid2     = "";
char* password2 = "";
char* host = "";
char* trigger = "";
char* trigger2 = "";
char* trigger3 = "";
char* triggerKey = "";

int inputPin = D8;  // pushbutton connected to digital pin D3
#define buttonPin D8        // analog input pin to use as a digital input
int val = 0;        // variable to store the read value

void setup() {
  config();
  pinMode(BUILTIN_LED, OUTPUT);  // set onboard LED as output
  digitalWrite(BUILTIN_LED, 1);  // turning offLED
  pinMode(inputPin, INPUT);      // set pin as input
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  Serial.print("Connecting");
  int wait = 0;
  int timeoutConnect = 20;
  char* connectedSSID = "";
  // Wait for successful connection
  while (WiFi.status() != WL_CONNECTED && wait < timeoutConnect) {
    delay(500);
    Serial.print(".");
    wait++;
  }
  if(WiFi.status() == WL_CONNECTED){
    connectedSSID = ssid;
  }
  if(wait == timeoutConnect){
    WiFi.begin(ssid2, password2);
    Serial.print("Connecting alternative");
    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
    }
    if(WiFi.status() == WL_CONNECTED){
      connectedSSID = ssid2;
    }
  }
  Serial.println("");
  Serial.print("Connected to: ");
  Serial.println(connectedSSID);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.println("");
  digitalWrite(BUILTIN_LED, 0);  // turning on LED
}

void loop() {
  /*
  val = digitalRead(inputPin);     // read the input pin
  digitalWrite(BUILTIN_LED, val);  // sets the LED to the button's value
  //Serial.println(val);
  */
//   val = digitalRead(inputPin);
//  if(val == 1){
//    callIfttt();
//  }
  int b = checkButton();
   if (b == 1) callIfttt();
   if (b == 2) callIfttt2();
   if (b == 3) callIfttt3();
   if(b != 0){
    Serial.println(b);
   }
//   if (b == 3) holdEvent();
//   if (b == 4) longHoldEvent();

}

void callIfttt(){
  
  Serial.print("connecting to ");
  Serial.println(host);

  // Use WiFiClient class to create TCP connections
  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }

  // We now create a URI for the request
  String url = "/trigger/";
  url += trigger;
  url += "/with/key/";
  url += triggerKey;

  Serial.print("Requesting URL: ");
  Serial.println(url);

  // This will send the request to the server
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");
  delay(10);

  // Read all the lines of the reply from server and print them to Serial
  Serial.println("Respond:");
  while(client.available()){
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }

  Serial.println();
  Serial.println("closing connection");
  delay(200);
  digitalWrite(BUILTIN_LED, 1);  // turning off LED
  delay(200);
  digitalWrite(BUILTIN_LED, 0);  // turning on LED
  delay(200);
  digitalWrite(BUILTIN_LED, 1);  // turning off LED
  delay(200);
  digitalWrite(BUILTIN_LED, 0);  // turning on LED
}
void callIfttt2(){
  
  Serial.print("connecting to ");
  Serial.println(host);

  // Use WiFiClient class to create TCP connections
  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }

  // We now create a URI for the request
  String url = "/trigger/";
  url += trigger2;
  url += "/with/key/";
  url += triggerKey;

  Serial.print("Requesting URL: ");
  Serial.println(url);

  // This will send the request to the server
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");
  delay(10);

  // Read all the lines of the reply from server and print them to Serial
  Serial.println("Respond:");
  while(client.available()){
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }

  Serial.println();
  Serial.println("closing connection");
  delay(200);
  digitalWrite(BUILTIN_LED, 1);  // turning off LED
  delay(200);
  digitalWrite(BUILTIN_LED, 0);  // turning on LED
  delay(200);
  digitalWrite(BUILTIN_LED, 1);  // turning off LED
  delay(200);
  digitalWrite(BUILTIN_LED, 0);  // turning on LED
}
void callIfttt3(){
  
  Serial.print("connecting to ");
  Serial.println(host);

  // Use WiFiClient class to create TCP connections
  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }

  // We now create a URI for the request
  String url = "/trigger/";
  url += trigger3;
  url += "/with/key/";
  url += triggerKey;

  Serial.print("Requesting URL: ");
  Serial.println(url);

  // This will send the request to the server
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");
  delay(10);

  // Read all the lines of the reply from server and print them to Serial
  Serial.println("Respond:");
  while(client.available()){
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }

  Serial.println();
  Serial.println("closing connection");
  delay(200);
  digitalWrite(BUILTIN_LED, 1);  // turning off LED
  delay(200);
  digitalWrite(BUILTIN_LED, 0);  // turning on LED
  delay(200);
  digitalWrite(BUILTIN_LED, 1);  // turning off LED
  delay(200);
  digitalWrite(BUILTIN_LED, 0);  // turning on LED
}
