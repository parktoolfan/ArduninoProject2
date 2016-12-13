#include <SPI.h>
#include <Ethernet.h>
#include <Wire.h>
byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};

//LCD Setup
#include <SoftwareSerial.h>
#include <ParallaxLCD.h>
ParallaxLCD lcd(6, 2, 16);

//Begin Amazon wireless setup
char serverNameAmazon[] = "s3.amazonaws.com"; // zoomkat's test web page server  web.comporium.net

//Begin Ifttt setup
char serverName[] = "maker.ifttt.com";
int totalCount = 0; //0
// change to your server's port
int serverPort = 80;
// change to the page on that server
char pageName[] = "/trigger/fromArduinoPayload/with/key/bLMBpfOKL5alWnYd1MMij3";
char params[32];

EthernetClient client;

//Establish Program output pins
const int buttonPin = 5;
int buttonState = 0;
int ledPin1 = 7;

//lastMessage will be the string that is the last text message recieved, we will compare this with newMessage to see if there has been a new text message.
String lastMessage;
String newMessage;

//Establish array for holding characters to send to our remote person
char recievedChars[30];
int numberofcharsrecieved = 0;

void setup() {
  Serial.begin(9600);
  //Signal Power
  pinMode(ledPin1, OUTPUT);
  digitalWrite(ledPin1, HIGH);
  pinMode(buttonPin, INPUT);

  //wire setup
  Wire.begin(); // join i2c bus (address optional for master)

  Serial.begin(9600);           // start serial for output

  //start LCD
  lcd.setup();
  delay(500);
  lcd.backLightOn();
  lcd.empty();

  //Start Ethernet
  Serial.print(F("Starting ethernet..."));
  if (!Ethernet.begin(mac)) Serial.println(F("failed"));
  else Serial.println(Ethernet.localIP());
  delay(2000);
  Serial.println(F("Ready"));
}

void loop() {
  //Begin lets try to put all this together
  //Maintain ethernet:
  Ethernet.maintain();
  Serial.println("Looping");
  //Blink LED
  digitalWrite(ledPin1, HIGH);
  delay(500);
  digitalWrite(ledPin1, LOW);
  delay(500);

  //Check if there is a message to send and if so, send it.
  buttonState = digitalRead(buttonPin);
  //Serial.print(buttonState);
  if (buttonState == 1) {
    // turn LED on:
    //Blink LED 3 times
    digitalWrite(ledPin1, HIGH);
    delay(100);
    digitalWrite(ledPin1, LOW);
    delay(100);
    digitalWrite(ledPin1, HIGH);
    delay(100);
    digitalWrite(ledPin1, LOW);
    delay(100);
    digitalWrite(ledPin1, HIGH);
    delay(100);
    digitalWrite(ledPin1, LOW);
    delay(100);

    char dataRecieved[30];
    int n = Wire.requestFrom(8, 30);
    for (int i = 0; i < n; i++) {
      dataRecieved[i] = Wire.read();
    }
    dataRecieved[27] = ' ';
    dataRecieved[28] = ' ';
    dataRecieved[29] = ' ';
    dataRecieved[30] = ' ';
    Serial.println(dataRecieved);
    //doPost("Jacob, Sending is Done!");
    doPost(dataRecieved);
    toPrint(dataRecieved);
    buttonState = 0;
  }

  //Recieving code
  sendGET(); //call send get. This will set value of newMessage.
  if (!(newMessage.equals(lastMessage))) {
    Serial.println("There is a New Message");
    char output[32];
    newMessage.toCharArray(output, 32);
    toPrint(output);
    //toPrint(output[]);
    Serial.println();
    lastMessage = newMessage;
  } else {
    Serial.println("No New Message.");
    Serial.println();
  }
  //delay 10 seconds at end
  delay(5000);
}

//Begin AMAZON S3 METHODS
//////////////////////////////////////////////////////////////////////////////////////////////////////

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
  char payloadArray[32];
  //Now clear array.
  for (int i = 0; i < sizeof(payloadArray); i = i + 1) {
    payloadArray[i] = ' ';
  }
  while (client.connected() || client.available()) { //connected or data available
    //    //client.readStringUntil(':');
    char c = client.read(); //gets byte from ethernet buffer
    //Serial.print(c); //prints raw feed for testing
    payloadArray[a] = c;
    a = a + 1;
  }
  Serial.print("Here is our array:     ");
  for (int i = 0; i < sizeof(payloadArray); i = i + 1) {
    Serial.print(payloadArray[i]);
  }
  Serial.println();

  String str(payloadArray);
  newMessage = payloadArray;

  client.stop(); //stop client
}

//Begin IFTTT POST METHODS
//////////////////////////////////////////////////////////////////////////////////////////////////////

void doPost(String a) {

  //Create Payload Message
  String ident = "value1=3175636398&value2=";
  String totalMessage = ident + a;

  Serial.print("totalMessage: ");
  Serial.println(totalMessage);

  if (!postPage(serverName, serverPort, pageName, totalMessage.c_str())) Serial.print(F("Fail "));
  else Serial.print(F("Pass "));
  totalCount++;
  Serial.println(totalCount, DEC);
}

byte postPage(char* domainBuffer, int thisPort, char* page, char* thisData)
{
  int inChar;
  char outBuf[64];

  Serial.print(F("connecting..."));

  if (client.connect(domainBuffer, thisPort) == 1)
  {
    Serial.println(F("connected"));

    // send the header
    sprintf(outBuf, "POST %s HTTP/1.1", page);
    client.println(outBuf);
    sprintf(outBuf, "Host: %s", domainBuffer);
    client.println(outBuf);
    client.println(F("Connection: close\r\nContent-Type: application/x-www-form-urlencoded"));
    sprintf(outBuf, "Content-Length: %u\r\n", strlen(thisData));
    client.println(outBuf);

    // send the body (variables)
    client.print(thisData);
    Serial.println("ThisData: ");
    Serial.println(thisData);
  }
  else
  {
    Serial.println(F("failed"));
    return 0;
  }

  int connectLoop = 0;

  while (client.connected())
  {
    while (client.available())
    {
      inChar = client.read();
      Serial.write(inChar);
      connectLoop = 0;
    }

    delay(1);
    connectLoop++;
    if (connectLoop > 10000)
    {
      Serial.println();
      Serial.println(F("Timeout"));
      client.stop();
    }
  }

  Serial.println();
  Serial.println(F("disconnecting."));
  client.stop();
  return 1;
}

//Begin LCD Methods
//////////////////////////////////////////////////////////////////////////////////////////////////////
void toPrint(char output[]) {
  lcd.empty();
  lcd.at(0, 0, output);
  delay(5000);
}

//Begin wire methods
//////////////////////////////////////////////////////////////////////////////////////////////////////
// function that executes whenever data is received from master
// this function is registered as an event, see setup()
//void receiveEvent(int howMany) {
//    Serial.println("RECIEVING FROM ARDUINO");
//    int c = Wire.read(); // receive byte as a character
//    Serial.print(c);         // print the character
//
//}
