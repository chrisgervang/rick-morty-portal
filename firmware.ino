// This #include statement was automatically added by the Particle IDE.
#include <clickButton.h>

int button = D7; 
// Button results 
int function = 0;

ClickButton button1(button, HIGH);

void setup() {
  pinMode(button,INPUT_PULLDOWN); // Our on-board LED is output as well
  
  // Setup button timers (all in milliseconds / ms)
  // (These are default if not set, but changeable for convenience)
  button1.debounceTime   = 20;   // Debounce timer in ms
  button1.multiclickTime = 250;  // Time limit for multi clicks
  button1.longClickTime  = 500; // time until "held-down clicks" register
}

void loop() {
  
  // Update button state
  button1.Update();

  // Save click codes in LEDfunction, as click codes are reset at next Update()
  if(button1.clicks != 0) function = button1.clicks;
  
  if(function == 1) {
    // SINGLE click
    Particle.publish("video","in-out",60,PRIVATE);
  }

  if(function == 2) {
    // DOUBLE click
    Particle.publish("video","loop",60,PRIVATE);
  }
  
//   if(function == 3) Serial.println("TRIPLE click");

  if(function == -1) {
    // SINGLE LONG click
    Particle.publish("video","off",60,PRIVATE);
  }

//   if(function == -2) Serial.println("DOUBLE LONG click");
//   if(function == -3) Serial.println("TRIPLE LONG click");
  
  function = 0;
  delay(5);

}