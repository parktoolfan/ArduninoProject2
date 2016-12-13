int speakerPin = 13;

const int dotBeat = 30;
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
  for (int i = 0; i < 1; i++) {
    if (names[i] == note) {
      playTone(tones[i], duration);
    }
  }
}


/////////////////////////////////////////////////////////////////////////////

const int buttonPin1 = 2; 
const int buttonPin2 = 3;
const int buttonPin3 = 4;
const int ledPin1 = 8;       
const int ledPin2 = 9;
const int ledPin3 = 10;

int dotLED = 50; // A dot is one time unit (50 ms); can adjust as needed.
int dashLED = 3 * dotLED; // In morse code, a dash is three time units.

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
"     " // Space
};

// This array contains the letters and numbers that the user input will be translated to.
char alphaNum[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
'0', '1', '2', '3', '4', '5',
'6', '7', '8', '9'};

// This array contains the final user text:
char userText[] = "          ";
// We need a variable to keep track of which indice of userText to add a char.
int textIndex = 0;


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
     delay(dotLED);
     digitalWrite(ledPin1, LOW);
     delay(dotLED);
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
     if ((buttonPushCounter1 + buttonPushCounter2) == 5) { // This branch is entered if the user has already entered 5 inputs.
        Serial.print("Current morse code entry: ");
        for (int i = 0; i < 5; i++) {
          Serial.print(singleMorse[i]);
        }
        Serial.println("");
       // IMPORTANT: Translate: We do this by comparing the user input (singleMorse) a "library" of morse code Arrays.
       for(int i = 0; i < 37; i++) {
         if (strcmp(singleMorse, morseCode[i]) == 0) {
            Serial.println("Match!");
            Serial.println(alphaNum[i]);
            
//            // Fill userText index with the appropiate character.
//            userText[textIndex] = alphaNum[i];
//            textIndex++; //We increment the variable to show that a translation has occured.
         }
         else {
            // No match found.
         }
       }
       buttonPushCounter1 = 0; // Reset buttonPushCounter1 to zero
       buttonPushCounter2 = 0; // Reset buttonPushCounter2 to zero
       Serial.println("(buttonPushCounters 1 and 2 have been reset to zero.)");
       //singleMorse[] = "     "; // IMPORTANT: Array must be blanked before every entry.
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
     digitalWrite(ledPin2, HIGH);   // turn the LED on (HIGH is the voltage level)
     delay(dashLED);
     digitalWrite(ledPin2, LOW);
     delay(dotLED);
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
        Serial.print("Current morse code entry: ");
        for (int i = 0; i < 5; i++) {
          Serial.print(singleMorse[i]);
        }
        Serial.println("");
        // IMPORTANT: Translate: We do this by comparing the user input (singleMorse) a "library" of morse code Arrays.
        for(int i = 0; i < 37; i++) {
          if (strcmp(singleMorse, morseCode[i]) == 0) {
            Serial.println("Match!");
            Serial.println(alphaNum[i]);
          }
          else {
          // No match found.
          }
        }
        buttonPushCounter1 = 0; // Reset buttonPushCounter1 to zero
        buttonPushCounter2 = 0; // Reset buttonPushCounter2 to zero
        Serial.println("(buttonPushCounters 1 and 2 have been reset to zero.)");
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
    // First, turn on the LED briefly to signify that the button was pressed.
     digitalWrite(ledPin3, HIGH);   // turn the LED on (HIGH is the voltage level)
     delay(50);
     digitalWrite(ledPin3, LOW);
     buttonPushCounter3++;
     Serial.println("on");
     Serial.print("number of 3rd button pushes:  ");
     Serial.println(buttonPushCounter3);
     buttonPushCounter1 = 0; // Reset buttonPushCounter1 to zero
     buttonPushCounter2 = 0; // Reset buttonPushCounter2 to zero
     Serial.println("(buttonPushCounters 1 and 2 have been reset to zero.)");
     Serial.print("Current morse code entry: ");
     for (int i = 0; i < 5; i++) {
        Serial.print(singleMorse[i]);
     }
     Serial.println("");
     // IMPORTANT: Translate: We do this by comparing the user input (singleMorse) a "library" of morse code Arrays.
     for(int i = 0; i < 37; i++) {
       if (strcmp(singleMorse, morseCode[i]) == 0) {
          Serial.println("Match!");
          Serial.println(alphaNum[i]);
       }
       else {
            // No match found.
       }
     }
     Serial.println("User's current input (English): ");
     for(int i = 0; i < 10; i++) {
       Serial.print(userText[i]);
     } //This doesn't work because you need an overall counter to decide where to put this letter
   }
   else {
     Serial.println("off");
   }
   
   delay(50);
 }
 lastButtonState3 = buttonState3;
}


