/*
   Web client sketch for IDE v1.0.1 and w5100/w5200
   Uses POST method.
   Posted November 2012 by SurferTim
*/

#include <SPI.h>
#include <Ethernet.h>

byte mac[] = {  
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

//Change to your server domain
char serverName[] = "maker.ifttt.com";

// change to your server's port
int serverPort = 80;

// change to the page on that server
char pageName[] = "/trigger/fromArduinoPayload/with/key/bLMBpfOKL5alWnYd1MMij3";

EthernetClient client;
int totalCount = 0; //0
// insure params is big enough to hold your variables
char params[32];
//char params[] = "hello";

// set this to the number of milliseconds delay
// this is 30 seconds
#define delayMillis 5000UL

unsigned long thisMillis = 0;
unsigned long lastMillis = 0;

void setup() {
  Serial.begin(9600);

  // disable SD SPI
  pinMode(4,OUTPUT);
  digitalWrite(4,HIGH);

  Serial.print(F("Starting ethernet..."));
  if(!Ethernet.begin(mac)) Serial.println(F("failed"));
  else Serial.println(Ethernet.localIP());

  delay(2000);
  Serial.println(F("Ready"));
}

void loop()
{
  // If using a static IP, comment out the next line
  Ethernet.maintain();

  thisMillis = millis();

  if(thisMillis - lastMillis > delayMillis)
  {
    lastMillis = thisMillis;

    // params must be url encoded.
    //sprintf(params,"value1=%i",totalCount); //totalCount  //temp1
    if(!postPage(serverName,serverPort,pageName,"value1=3175636398&value2=Jake this is from an arduino. Thanks Sam!")) Serial.print(F("Fail "));
    else Serial.print(F("Pass "));
    totalCount++;
    Serial.println(totalCount,DEC);
  }    
}


byte postPage(char* domainBuffer,int thisPort,char* page,char* thisData)
{
  int inChar;
  char outBuf[64];

  Serial.print(F("connecting..."));

  if(client.connect(domainBuffer,thisPort) == 1)
  {
    Serial.println(F("connected"));

    // send the header
    sprintf(outBuf,"POST %s HTTP/1.1",page);
    client.println(outBuf);
    sprintf(outBuf,"Host: %s",domainBuffer);
    client.println(outBuf);
    client.println(F("Connection: close\r\nContent-Type: application/x-www-form-urlencoded"));
    sprintf(outBuf,"Content-Length: %u\r\n",strlen(thisData));
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

  while(client.connected())
  {
    while(client.available())
    {
      inChar = client.read();
      Serial.write(inChar);
      connectLoop = 0;
    }

    delay(1);
    connectLoop++;
    if(connectLoop > 10000)
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
