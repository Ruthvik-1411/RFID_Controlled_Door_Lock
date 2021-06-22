# RFID Controlled door lock with LCD screen display
<b> Working</b><br>
   First a message is dispayed on the LCD screen saying to scan the tag.<br>
   Now when the RFID tag is placed near the RFID scanner it gets scanned. Every RFID tag has a unique UID tag. 
   This UID is printed on the screen as ID: XX XX XX XX.<br>
   Now if this ID has the access rights then a message appears on the LCD screen saying Hello "USER" depending 
   on the user.<br>
   The servo which controls the lock is made to turn so that the door gets unlocked. After five seconds the door gets locked making the servo to its initial
   position. The screen is cleared and when a new tag is kept, it displays the message and unlocks the door again.<br> 
   If the tag doesn't have access rights then access is denied and the corresponding message is displayed.
   The servo remains locked in its initial position.<br><br>
   
<b> Here is the link to implementation video: <a href="https://drive.google.com/file/d/1KRWoHpIizJNbBw2IwhC9x1CrXQk4oW4b/view?usp=sharing"> video link </a>
