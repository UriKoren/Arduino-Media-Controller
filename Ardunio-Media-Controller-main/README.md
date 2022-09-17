# ArduinoMediaController  
![Capture](https://user-images.githubusercontent.com/55280978/137301444-8ed637ee-f7ff-42fc-adc5-d74d866ff1f7.PNG)
<br/><br/>
<b>an arduino project in cpp and python for media control.  
project done by shai ely and uri koren from sapir academic college.</b>  


<h2>what you need for this project:</h2>  



- Arduino Uno.
- 2 Ultrasonic sensors.
- 1 light dependent resistor.
- matrix.
- some cables.
- some tape.

<h2>project gestures:</h2>


- 1-10 cm from the ultrasonic: right sensor run media forward, left backward.  
- 10-25 from the ultrasonic: right sensor turn volume up, left sensor turn volume down.  
- both hands together 30-50 cm from both ultrasonics: pause or start a media.  
- both hands together 5-20 cm from both ultrasonics for 3 seconds: exit the media.  
- changes screen brightness based on the light in the room - lowlight = low brightness, highlight = high brightness.  


<h2>Libraries in use:</h2>


- Serial.
- Pyautogui.
- Screen_brightness_control.

