//Deklarasi Variabel
#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>

//Deklarasi Wifi untuk update data
const char* ssid     = "bay bay";
const char* password = "qazwsxedc";

//Deklarasi web api untuk mengambil data
const char* host = "192.168.43.51";
//const char* streamId   = "....................";
//const char* privateKey = "....................";

//Deklarasi variabel untuk menampung data dari web api
String data_stream;

//Deklarasi Wifi access point untuk mentrasfer data ke gadget
const char *ssid_AP = "test_esp";
const char *password_AP = "123456789";

//Deklarasi Web server access point
ESP8266WebServer server(80);

//Deklarasi fungsi untuk mengirimkan data dari web api ke gedget
void handleRoot() {
  server.send(200, "text/html", data_stream);
  //server.send(200, "text/html", data_stream);
}

void setup() {
  Serial.begin(115200);
  delay(10);

  //=============================================

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  //=============================================

  
  //kode untuk konek ke wifi yang terkoneksi internet
  //dan kode untuk mengambil data dari web api serta menyimpannya di variabel data_stream
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  Serial.print("connecting to ");
  Serial.println(host);
  
  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }

  //sesuaikan dengan web api anda
  String url = "/web_api_esp/index.php/welcome/testing";
  //url += streamId;
  //url += "?private_key=";
  //url += privateKey;
  //url += "&value=";
  //url += value;
  //======================================
  
  Serial.print("Requesting URL: ");
  Serial.println(url);
  
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");
  unsigned long timeout = millis();
  while (client.available() == 0) {
    if (millis() - timeout > 5000) {
      Serial.println(">>> Client Timeout !");
      client.stop();
      return;
    }
  }
  
  while(client.available()){
    String line = client.readStringUntil('\r');
    data_stream = line;
  }
  Serial.print(data_stream);
  //kode untuk wifi internet selesai
  //=======================================================

  
  //kode untuk membuat wifi access point
  //dan kode untuk menstrasfer data ke gedget
  Serial.println();
  Serial.println("closing connection");

  Serial.println();
  Serial.print("Configuring access point...");
  
  WiFi.softAP(ssid_AP, password_AP);

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  server.on("/", handleRoot);
  server.begin();
  Serial.println("HTTP server started");
  //kode untuk membuat dan mentrasfer data telah selesai

  
}

void loop() {

  //kode untuk mengecek gedget apa aja yg konek
  //dan gedget apa aja yang meminta data dari chip ini
  server.handleClient();
}

