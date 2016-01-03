//   Heart2.1
//   Richard Hawthorn
//   Cambridge Hackspace
//   2015-12-24
//
//   Uses an ATTiny44 @ 8Mhz
//
//   Led Layout
//
//      1     2
//   3  4  5  6  7
//   8  9  10 11 12
//      13 14 15
//         16

//define led charlieplex pins
int led[] = {0,1,2,3,10};

//max brightness (default 100)
int max_brightness = 100;

//number of seconds between each pulse (default 10)
int pulse_seconds = 10;

//setup the counter, for the pulsing
long counter = 0;

//are we increasing brightness, or decreasing
bool up = true;

// **************************************
// Setup
// **************************************

void setup() {

  //start with a 5 second delay
  delay(5000);
  
}

// **************************************
// Main Loop
// **************************************

void loop() {

  //incrament/decrament the counter as we loop though the code
  if (up == true){
    counter++;
  } else {
    counter--;
  }

  //count until we hit max brightness
  if (counter >= max_brightness){
    //flip the counting
    up = false;
  }

  //we have completed one pulse
  if (counter == 0){
    //flip the counting
    up = true;

    //sleep for the required number of seconds
    delay(pulse_seconds * 1000);
  }

  //loop through the leds
  for (int i = 0; i <= 4; i++){
    pinMode(led[i], OUTPUT); 
    digitalWrite(led[i], LOW); 
    
    for (int j = 0; j <= 4; j++){
      if (i != j){
        pinMode(led[j], OUTPUT);
        digitalWrite(led[j], HIGH); 

        //delay while the specified led is on
        delayMicroseconds(counter);
        
        digitalWrite(led[j], LOW); 
        pinMode(led[j], INPUT);
      }
    }
    
    digitalWrite(led[i], HIGH); 
    pinMode(led[i], INPUT); 

    //delay while the led is off
    delayMicroseconds(1000 - counter);
    
  }

}
