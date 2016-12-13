


//////////////////////////////////////////////////////////////////////////
int speakerPin = 13;

const int dotBeat = 60; // For our purposes, the dot beat is a single unit of time (in morse code, a dot is one unit, while a dash is three unts).
const int dashBeat = 3 * dotBeat;

int length = 1; // the number of notes
char notes[] = "C"; // a space represents a rest
int beats[] = {1};
int tempo = 300;

void playTone(int tone, int duration) {
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(speakerPin, HIGH);
    delayMicroseconds(tone);
    digitalWrite(speakerPin, LOW);
    delayMicroseconds(tone);
  }
}

void playNote(char note, int duration) {
  char names[] = { 'C' };
  int tones[] = { 956 };
  
  // play the tone corresponding to the note name

  playTone(tones[0], duration);
}


/////////////////////////////////////////////////////////////////////////////

const int buttonPin1 = 2; 
const int buttonPin2 = 3;
const int buttonPin3 = 4;
const int ledPin1 = 8;       
const int ledPin2 = 9;
const int ledPin3 = 10;

int buttonPushCounter1 = 0;   
int buttonState1 = 0;        
int lastButtonState1 = 0;   

int buttonPushCounter2 = 0; 
int buttonState2 = 0;
int lastButtonState2 = 0;

int buttonPushCounter3 = 0; 
int buttonState3 = 0;
int lastButtonState3 = 0;

// Array to hold the chars 
char singleMorse[] = "     ";
char* morseCode[] = {".-   ", "-... ", "-.-. ", "-..  ", ". ", "..-. ", "--.  ", ".... ", "..   ", // A-I
".--- ", "-.-  ", ".-.. ", "--   ", "-.   ", "---  ", ".--. ", "--.- ", ".-.  ", // J-R 
"...  ", "-    ", "..-  ", "...- ", ".--  ", "-..- ", "-.-- ", "--.. ", // S-Z
"-----", ".----", "..---", "...--", "....-", ".....", // 0-5
"-....", "--...", "---..", "----.", // 6-9
"     "
};

// This array contains the letters and numbers that the user input will be translated to.
char alphaNum[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
'0', '1', '2', '3', '4', '5',
'6', '7', '8', '9', '_'};

// This array contains the final user text:
char userText[] = "                              ";
// Variable to keep track of where to add characters to userText.
int textIndex = 0;
char charIndex = 'a';

void setup() {
 pinMode(speakerPin, OUTPUT);
 
 pinMode(buttonPin1, INPUT);
 pinMode(ledPin1, OUTPUT);
 Serial.begin(9600);
 
 pinMode(buttonPin2, INPUT);
 pinMode(ledPin2, OUTPUT);
 Serial.begin(9600);

 pinMode(buttonPin3, INPUT);
 pinMode(ledPin3, OUTPUT);
 Serial.begin(9600);
}

void loop() {
 buttonState1 = digitalRead(buttonPin1);

 if (buttonState1 != lastButtonState1) {
   if (buttonState1 == LOW) {
     // First, turn on the LED briefly to signify that the button was pressed.
     digitalWrite(ledPin1, HIGH);   // turn the LED on (HIGH is the voltage level)
     delay(dotBeat);
     digitalWrite(ledPin1, LOW);
     delay(dotBeat);
     // Also, briefly play a note to correspond with the appropriate character:
     playNote(notes[0], dotBeat);
    
 
     buttonPushCounter1++;
     Serial.println("on");
     Serial.print("number of 1st button pushes:  ");
     Serial.println(buttonPushCounter1);
     // We need to "translate" a button bush into the appropiate character: - or .
     singleMorse[(buttonPushCounter1 + buttonPushCounter2) - 1] = '.';

     Serial.print("Current overall button count: ");
     Serial.println(buttonPushCounter1 + buttonPushCounter2);
     if ((buttonPushCounter1 + buttonPushCounter2) == 5) { // We do this because the max number of morse characters for translation is 5 (for our purposes).
        fullArray12(); // Call the function to translate the array
     }
     
   } 
   else {
     Serial.println("off");
   }
   delay(50);
 }
 lastButtonState1 = buttonState1;


 
 buttonState2 = digitalRead(buttonPin2);

 if (buttonState2 != lastButtonState2) {
   if (buttonState2 == LOW) {
    // First, turn on the LED briefly to signify that the button was pressed.
     digitalWrite(ledPin1, HIGH);   // turn the LED on (HIGH is the voltage level)
     delay(dashBeat);
     digitalWrite(ledPin1, LOW);
     delay(dotBeat);

     // Also, briefly play a note to correspond with the appropriate character:
     playNote(notes[0], dashBeat); 
     
     buttonPushCounter2++;
     Serial.println("on");
     Serial.print("number of 2nd button pushes:  ");
     Serial.println(buttonPushCounter2);
    // We need to "translate" a button bush into the appropiate character: - or .
     singleMorse[(buttonPushCounter1 + buttonPushCounter2) - 1] = '-';

     Serial.print("Current overall button count: ");
     Serial.println(buttonPushCounter1 + buttonPushCounter2);
     if ((buttonPushCounter1 + buttonPushCounter2) == 5) {
       fullArray12();
     }
   } 
   else {
     Serial.println("off");
   }
   delay(50);
 }
 lastButtonState2 = buttonState2;


 buttonState3 = digitalRead(buttonPin3);
 
 if (buttonState3 != lastButtonState3) {
   if (buttonState3 == LOW) {
     buttonPushCounter3++;
     Serial.println("on");
     Serial.print("number of 3rd button pushes:  ");
     Serial.println(buttonPushCounter3);
     fullArray12();
   }
   else {
     Serial.println("off");
   }
   
   delay(50);
 }
 lastButtonState3 = buttonState3;
}


void storeChar(char c) { // The function takes in an argument, a character, and stores it in the final user array.
  userText[textIndex] = c;
  textIndex++; // Move to next index for next char storage.
}

void fullArray12() {
  // First, signal the blue light; this indicates that a letter is to be translated.

  for(int fadeValue = 0 ; fadeValue <= 255; fadeValue +=51) { 
    // sets the value (range from 0 to 255):
    analogWrite(ledPin3, fadeValue);         
    // wait for 30 milliseconds to see the dimming effect    
    delay(30);                            
    } 
    // fade out from max to min in increments of 5 points:
  for(int fadeValue = 255 ; fadeValue >= 0; fadeValue -=51) { 
    // sets the value (range from 0 to 255):
    analogWrite(ledPin3, fadeValue);         
    // wait for 30 milliseconds to see the dimming effect    
    delay(30);                            
  } 
  Serial.print("Current morse code entry: ");
  for (int i = 0; i < 5; i++) {
    Serial.print(singleMorse[i]);
  }
  Serial.println("");
  // IMPORTANT: Translate: We do this by comparing the user input (singleMorse) a "library" of morse code Arrays.
  for(int i = 0; i < 37; i++) {
    if (strcmp(singleMorse, morseCode[i]) == 0) {
      Serial.println("Match!");
      Serial.println(alphaNum[i]); // Print the corresponding alphanumerical character.
      charIndex = alphaNum[i]; // Store in variable.
      storeChar(charIndex); // Call the function, and pass the variable to the functions parameters.
      break;
    }
    else {
    // No match found.
      if (i == 36) {
        digitalWrite(ledPin2, HIGH);   // turn the LED on (HIGH is the voltage level)
        delay(30);
        digitalWrite(ledPin2, LOW);
        delay(30);
      }
    }
  }
  // Important: Clear the morse code user input.
  for (int i = 0; i < 5; i++) {
    singleMorse[i] = ' ';
  }
  Serial.print("User's current input (English): ");
  for(int i = 0; i < 33; i++) {
    Serial.print(userText[i]);
  } 
  buttonPushCounter1 = 0; // Reset buttonPushCounter1 to zero
  buttonPushCounter2 = 0; // Reset buttonPushCounter2 to zero
  Serial.println("");
  Serial.println("(buttonPushCounters 1 and 2 have been reset to zero.)"); 
  
}


