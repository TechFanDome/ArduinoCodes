#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

const char* ssid = "ESP-01";  
const char* password = "HITLERJD";   //
bool toggle=0;                  
ESP8266WebServer server(80);    

void handleRoot() {
  //toggle=!toggle;               
    digitalWrite(2,HIGH);     
        String s = "\r\n\r\n  <!DOCTYPE HTML>\r\n<html><h1>Esp8266 Communication</h1> ";
        s += "<p>Success!!!</html>\r\n\r\n";  
        server.send(200,"text/html",s);      
}
void handleoff(){
          digitalWrite(2,LOW);
           String s = "\r\n\r\n  <!DOCTYPE HTML>\r\n<html><h1>Esp8266 Communication</h1> ";
           s += "<p>Success!!!</html>\r\n\r\n";  
           server.send(200,"text/html",s);     
  
  
  }
void setup() {
  bool toggle=0;   
  delay(200);                           
  Serial.begin(115200);                 
  pinMode(2, OUTPUT);                  
  WiFi.softAP(ssid, password);      
  digitalWrite(2,LOW);
  IPAddress myIP = WiFi.softAPIP();    
  Serial.print("AP IP address: ");
  Serial.println(myIP);         
  server.on("/Led", handleRoot);           
  server.on("/off",handleoff);
  server.begin();                       
  Serial.println("Server started");
}

void loop() {
  Serial.println("Waiting For LINK");  
  server.handleClient();
}
