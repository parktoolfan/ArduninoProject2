/*
OpenJumper WebServer Example
Establish an Arduino server displaying sensor information
[url=http://www.openjumper.com/]http://www.openjumper.com/[/url]
[url=http://x.openjumper.com/ethernet/]http://x.openjumper.com/ethernet/[/url]
*/

#include <SPI.h>
#include <Ethernet.h>

// Set the MAC address、IP address
// IP address need to refer to your local network configuration
byte mac[] = { 
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(168,0,1,2);

// Initialize Ethernet Library
// HTTP default port is 80
EthernetServer server(80);

void setup() {
// Initialize serial port
  Serial.begin(9600);

  // Open ethernet connection and initialization for the server
  Ethernet.begin(mac, ip);
  server.begin();
  Serial.print("server is at ");
  Serial.println(Ethernet.localIP());
}

void loop() {
  // monitor client date
  EthernetClient client = server.available();
  if (client) {
    Serial.println("new client");
    // a HTTP request must have character return at the end
    boolean currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.write(c);
        // If receive empty line, HTTP request will be ended and sent out the message
        if (c == '\n' && currentLineIsBlank) {
          // Send standard HTTP reply
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("Connection: close");
          client.println();
          client.println("<!DOCTYPE HTML>");
          client.println("<html>");
          // added a meta refresh tag, browser will refresh every 5 seconds
          // If this refresh rate is too high，the web page may be hanged
          client.println("<meta http-equiv=\"refresh\" content=\"5\">");
          // print out the every data value from the analog port
          for (int analogChannel = 0; analogChannel < 6; analogChannel++) {
            int sensorReading = analogRead(analogChannel);
            client.print("analog input ");
            client.print(analogChannel);
            client.print(" is ");
            client.print(sensorReading);
            client.println("<br />");       
          }
          client.println("</html>");
          break;
        }
        if (c == '\n') {
          // Started a new line
          currentLineIsBlank = true;
        } 
        else if (c != '\r') {
          // If there is already got a character
          currentLineIsBlank = false;
        }
      }
    }
    // waiting the browser receiving data
    delay(1);
    // close the connection
    client.stop();
    Serial.println("client disonnected");
  }
}
