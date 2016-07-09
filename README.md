# wemos-iot-button

Simple iot button that use ifttt as service provider. It will connect to predefined ssid and password (with alternative). and one the button clicked, it will `ping` ifttt trigger, that you can use to trigger anything on ifttt

I find it is useful to annoy my wife (by using the trigger to send her email from my email). If you find another purpose please do tell me.

Setup
=======
made one file named `configuration.ino` at the same folder as `wemos_iot_button.ino`. Populate the file with these codes. (remember to change to your ssid, password and ifttt button key) 

```processing
#include "Arduino.h"
void config(){
  ssid     = "ssid name";
  password = "password for ssid";
  ssid2     = "alternative ssid";
  password2 = "password for alternative ssid";
  host = "maker.ifttt.com";
  trigger = "your trigger on ifttt";
  triggerKey = "your key on ifttt";
}
```

then compile and upload to your wemos r2/d1 mini using Arduino
