# wemos-iot-button

Simple iot button that use ifttt as service provider. It will connect to predefined ssid and password (with alternative). and when the button clicked (or double clicked), it will `ping` ifttt trigger, that you can use to trigger anything on ifttt. (will add step by step later)

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
  trigger2 = "your trigger on ifttt on doubleclick event";
  trigger3 = "your trigger on ifttt on hold (1 second) event";
  triggerKey = "your key on ifttt";
}
```

then compile and upload to your wemos r2/d1 mini using Arduino

USAGE (that I know)
=========
- annoy my wife by spamming her email
- now my wife want one that could notify my desktop if she needs me to answer the phone


CREDITS
==========
- DoubleClick on button using code from Jeff Saltzman on [arduino forum](http://forum.arduino.cc/index.php?topic=14479.0)

