# bcd_customkey

## Install Arduino 
https://www.arduino.cc/en/Main/OldSoftwareReleases

Open bcd_customerkey.ino, will ask you to create a folder for it.

## Select the COM# port in Tools/Port
![image](https://www.arduino.cc/en/uploads/Guide/Micro_SelPort.jpg)

## IMPORTANT Select Arduino Leonardo in Tools/Board
![image](https://www.kmpelectronics.eu/portals/0/Projects/Arduino/Images/SelectArduinoLeonardo.png)


## Modification Example (Windows)
Each key press performs the following

String key02 = "taskmgr";

     Keyboard.press(KEY_LEFT_GUI);  #Left Windows Key
     Keyboard.press('r');  # r key with Windows key pressed
     delay(100);  # wait for 100ms
     Keyboard.releaseAll();  # release all keys
     Keyboard.println(key02);  # print out string key02 (taskmgr)
     Keyboard.press(KEY_RETURN);  # press Enter
     Keyboard.releaseAll();  # release all keys
     break; 
     
## Modification Example (Mac)
Each key press performs the following

String key02 = "taskmgr";

     Keyboard.press(KEY_LEFT_GUI);  #Left Windows Key
     Keyboard.press(' ');  # r key with Windows key pressed
     delay(100);  # wait for 100ms
     Keyboard.releaseAll();  # release all keys
     Keyboard.println(key06);  # print out string key06
     Keyboard.press(KEY_RETURN);  # press Enter
     Keyboard.releaseAll();  # release all keys
     break; 
