//zoomkat 5-13-13
//simple client test
//for use with IDE 1.0
//open serial monitor and send an e to test
//for use with W5100 based ethernet shields

//Begin wireless setup
#include <SPI.h>
#include <Ethernet.h>
byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};
char serverNameAmazon[] = "s3.amazonaws.com"; // zoomkat's test web page server  web.comporium.net
EthernetClient client;

String readString, readString1;
int x = 0; //for counting line feeds
char lf = 10; //line feed character
//////////////////////

String lastMessage;

void setup() {

  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
    // no point in carrying on, so do nothing forevermore:
    while (true);
  }
  Serial.begin(9600);
  Serial.println("Better client test 5/13/13"); // so I can keep track of what is loaded
  Serial.println("Send an e in serial monitor to test"); // what to do to test
}

void loop() {
  // check for serial input
  if (Serial.available() > 0) //if something in serial buffer
  {
    byte inChar; // sets inChar as a byte
    inChar = Serial.read(); //gets byte from buffer
    if (inChar == 'e') // checks to see byte is an e
    {
      sendGET(); // call sendGET function below when byte is an e
    }
  }
}

//////////////////////////

void sendGET() //client function to send/receive GET request data.
{
  if (client.connect(serverNameAmazon, 80)) {  //starts client connection, checks for connection
    //Serial.println("connected");
    Serial.println();
    client.println("GET /arduinoproject/s3conversation.txt HTTP/1.1"); //download text
    client.println("Host: s3.amazonaws.com");
    client.println("Connection: close");  //close 1.1 persistent connection
    client.println(); //end of get request
  }
  else {
    Serial.println("connection failed"); //error message if no client connect
    Serial.println();
  }

  while (client.connected() && !client.available()) delay(1); //waits for data to be downloaded

  while (true) {
    if (client.peek() == 'b') {
      client.read();
      if (client.peek() == 'g') {
        client.read();
        if (client.peek() == 'g') {
          client.read();
          if (client.peek() == 'n') {
            client.read();
            break;
          }
        }
      }
    } else {
      client.read();
    }
  }
  int a = 0;
  char payloadArray[40];
  while (client.connected() || client.available()) { //connected or data available
    //    //client.readStringUntil(':');
    char c = client.read(); //gets byte from ethernet buffer
    Serial.print(c); //prints raw feed for testing
    payloadArray[a] = c;
    a = a + 1;
  }
  Serial.println();

  for (int i = 0; i < sizeof(payloadArray); i = i + 1) {
    Serial.print(payloadArray[i]);
  }
  String str(payloadArray);
  lastMessage = payloadArray;
  Serial.println();
  Serial.println();
  Serial.println();
  Serial.println();
  Serial.println(lastMessage);

  client.stop(); //stop client
}
