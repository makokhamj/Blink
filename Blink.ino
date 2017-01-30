// the setup function runs once when you press reset or power the board

int led = 13;
long tnow, tnext = 0;
int ledState = LOW;
/*
//FOR VARIABLE TIMING

int tperiod[4] = {1000, 500, 250, 125};  // blink rates: 1/2sec,1/sec,2/sec,4/sec
int tselect;
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(led, OUTPUT);
  tselect = 3;
}

// the loop function runs over and over again forever
void loop() {
/*  analogWrite(led, 512);   // turn the LED on (75% duty cycle)

  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);                       // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(20%);                    // wait for a second

  if (ledState == HIGH)
    ledState = LOW;
  else
    ledState = HIGH;
  digitalWrite (led, ledState);

  delay(tperiod[tselect]);
}


//ADDING USER INPUT

int keyF = 11;  // user button switch ==> faster
int keyS = 12;  // user button switch ==> slower

#define MAX_SELECT 4
int tperiod[MAX_SELECT] = {1000, 500, 250, 125};  // blink rates: 1/2sec,1/sec,2/sec,4/sec
int tselect;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);     
  pinMode(keyF, INPUT);
  pinMode(keyS, INPUT);
  tselect = 1;      // select blink rate = 1 per sec
}

// the loop routine runs over and over again forever:
void loop() {
  if (ledState == HIGH)
    ledState = LOW;            // HIGH -> LOW
  else
    ledState = HIGH;           // LOW -> HIGH
  digitalWrite(led,ledState);  // make LED ON/OFF same as updated ledState

  delay(1000);                 // wait for a sec

  if (readUserKeyF()) tselect = blinkFaster();
  if (readUserKeyS()) tselect = blinkSlower(); 
}

int blinkFaster(void) {
  if (tselect < MAX_SELECT-1)
    return (tselect+1);
  else
    return tselect;
}
int blinkSlower(void) {
  if (tselect > 0) 
    return (tselect - 1);
  else
    return tselect;
}

int readUserKeyF(void) {
  if (digitalRead(keyF) == LOW) return 1;
  else return 0;
}
int readUserKeyS(void) {
  if (digitalRead(keyS) == LOW) return 1;
  else return 0;
}
*/

// BLINKING WITHOUT (DELAY)

void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);     
}

// the loop routine runs over and over again forever:
void loop() {

  tnow = millis();           // get current millisec counter value

  if (tnow >= tnext) {       // is it time to change the ledState?
    // YES: time to change, reverse ledState: HIGH->LOW, LOW->HIGH

    if (ledState == HIGH)
      ledState = LOW;            // HIGH -> LOW
    else
      ledState = HIGH;           // LOW -> HIGH
    digitalWrite(led,ledState);  // make LED ON/OFF same as updated ledState

    tnext = tnow + 500;    // set time of next ledState change
  }
}

