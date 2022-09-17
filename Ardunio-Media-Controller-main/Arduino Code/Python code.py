import serial                                      
import pyautogui
import screen_brightness_control as sbc


Arduino_Serial = serial.Serial('com3',9600)

while 1:
    incoming_data = str (Arduino_Serial.readline()) 
    print (incoming_data)
    
    if 'highLight' in incoming_data:         
        sbc.set_brightness(100)
        
    if 'lowLight' in incoming_data:        
        sbc.set_brightness(20)

    if 'right' in incoming_data:            
        pyautogui.hotkey('right')           

    if 'left' in incoming_data:             
        pyautogui.hotkey('left')           

    if 'down' in incoming_data:             
        pyautogui.hotkey('down') 
         
    if 'up' in incoming_data:               
        pyautogui.hotkey('up')
        
    if 'space' in incoming_data:            
        pyautogui.hotkey('space')

    if 'exit' in incoming_data:             
        pyautogui.hotkey('alt', 'f4')



    incoming_data = "";
