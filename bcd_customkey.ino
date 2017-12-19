#include <Keyboard.h>
String youtube = "chrome.exe -incognito ";
String key02 = "taskmgr";
String key03 = "cmd";
String key04 = "powershell";
String key05 = "notepad";
String key06 = "steam://rungameid/570";
String key07 = "https://www.youtube.com/watch?v=dQw4w9WgXcQ";
String key08 = youtube + "https://youtu.be/dQw4w9WgXcQ?t=43s";
String key09 = youtube + "https://youtu.be/Yt-KMPvgKPo?t=1m30s";
String key10 = youtube + "https://youtu.be/RN4ttn6aBjg?t=5s";

#define DEBOUNCE 10  // how many ms to debounce, 5+ ms is usually plenty
 
//define the buttons that we'll use.
byte buttons[] = {2, 3, 4, 5, 6, 7, 8, 9, 10};
 
//determine how big the array up above is, by checking the size
#define NUMBUTTONS sizeof(buttons)
 
//track if a button is just pressed, just released, or 'currently pressed' 
byte pressed[NUMBUTTONS], justpressed[NUMBUTTONS], justreleased[NUMBUTTONS];
byte previous_keystate[NUMBUTTONS], current_keystate[NUMBUTTONS];
 
void setup() {
  byte i;
  // Make input & enable pull-up resistors on switch pins
  for (i=0; i< NUMBUTTONS; i++) {
    pinMode(buttons[i], INPUT);
    digitalWrite(buttons[i], HIGH);
  }
}
 
void loop() {
  byte thisSwitch=thisSwitch_justPressed()+2;
  switch(thisSwitch)
  {  
  case 2:
     Keyboard.press(KEY_LEFT_GUI);
     Keyboard.press('r');
     delay(100);
     Keyboard.releaseAll();
     Keyboard.println(key02);
     Keyboard.press(KEY_RETURN);
     Keyboard.releaseAll();
     break;  
  case 3: 
     Keyboard.press(KEY_LEFT_GUI);
     Keyboard.press('r');
     delay(100);
     Keyboard.releaseAll();
     Keyboard.println(key03);
     Keyboard.press(KEY_RETURN);
     Keyboard.releaseAll();
     break; 
  case 4: 
     Keyboard.press(KEY_LEFT_GUI);
     Keyboard.press('r');
     delay(100);
     Keyboard.releaseAll();
     Keyboard.println(key04);
     Keyboard.press(KEY_RETURN);
     Keyboard.releaseAll();
     break; 
  case 5: 
     Keyboard.press(KEY_LEFT_GUI);
     Keyboard.press('r');
     delay(100);
     Keyboard.releaseAll();
     Keyboard.println(key05);
     Keyboard.press(KEY_RETURN);
     Keyboard.releaseAll();
     break;  
  case 6: 
     Keyboard.press(KEY_LEFT_GUI);
     Keyboard.press('r');
     delay(100);
     Keyboard.releaseAll();
     Keyboard.println(key06);
     Keyboard.press(KEY_RETURN);
     Keyboard.releaseAll();
     break; 
  case 7: 
     Keyboard.press(KEY_LEFT_GUI);
     Keyboard.press(' ');
     delay(100);
     Keyboard.releaseAll();
     Keyboard.println(key07);
     Keyboard.press(KEY_RETURN);
     Keyboard.releaseAll();
     break;     
  case 8: 
     Keyboard.press(KEY_LEFT_GUI);
     Keyboard.press('r');
     delay(100);
     Keyboard.releaseAll();
     Keyboard.println(key08);
     Keyboard.press(KEY_RETURN);
     Keyboard.releaseAll();
     break; 
  case 9: 
     Keyboard.press(KEY_LEFT_GUI);
     Keyboard.press('r');
     delay(100);
     Keyboard.releaseAll();
     Keyboard.println(key09);
     Keyboard.press(KEY_RETURN);
     Keyboard.releaseAll();
     break;    
  case 10: 
     Keyboard.press(KEY_LEFT_GUI);
     Keyboard.press('r');
     delay(100);
     Keyboard.releaseAll();
     Keyboard.println(key10);
     Keyboard.press(KEY_RETURN);
     Keyboard.releaseAll();
     break;     
  }
}

void check_switches()
{
  static byte previousstate[NUMBUTTONS];
  static byte currentstate[NUMBUTTONS];
  static long lasttime;
  byte index;
  if (millis() < lasttime) {
    // we wrapped around, lets just try again
    lasttime = millis();
  }
  if ((lasttime + DEBOUNCE) > millis()) {
    // not enough time has passed to debounce
    return; 
  }
  // ok we have waited DEBOUNCE milliseconds, lets reset the timer
  lasttime = millis();
  for (index = 0; index < NUMBUTTONS; index++) {
    justpressed[index] = 0;       //when we start, we clear out the "just" indicators
    justreleased[index] = 0;
    currentstate[index] = digitalRead(buttons[index]);   //read the button
    if (currentstate[index] == previousstate[index]) {
      if ((pressed[index] == LOW) && (currentstate[index] == LOW)) {
        // just pressed
        justpressed[index] = 1;
      }
      else if ((pressed[index] == HIGH) && (currentstate[index] == HIGH)) {
        justreleased[index] = 1; // just released
      }
      pressed[index] = !currentstate[index];  //remember, digital HIGH means NOT pressed
    }
    previousstate[index] = currentstate[index]; //keep a running tally of the buttons
  }
}
 
byte thisSwitch_justPressed() {
  byte thisSwitch = 255;
  check_switches();  //check the switches &amp; get the current state
  for (byte i = 0; i < NUMBUTTONS; i++) {
    current_keystate[i]=justpressed[i];
    if (current_keystate[i] != previous_keystate[i]) {
      if (current_keystate[i]) thisSwitch=i;
    }
    previous_keystate[i]=current_keystate[i];
  }  
  return thisSwitch;
}
