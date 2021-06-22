# Rfid controlled door with Red and Green Led indication
<b>Working</b><br>
  There are two RFID tags each with a unique ID.<br>
  When the RFID tags are put close to the RFID scanner they get scanned.<br>
  Each tag has an ID and this ID is compared against the Ids with access controls.<br>
  If the tag has access then the servo moves unlocking the door and Green Led is Lit.
  The Message Hello "user" gets printed in the serial monitor according to the user.
  After 5 seconds of waiting the door closes automatically i.e. servo goes back to initial state and Led is OFF.<br>
  If the tag has no access then a Red Led glows and servo remains in initial position.
  It waits for 2 seconds and then offs the Led and continues to scan for a tag.<br>

A card or key is scanned and if it has access, the door opens and closes after five seconds and if it doesn't have access it lits a red Led or on the buzzer depending on the use.<br>
The card can be rescanned again if there is an issue.<br><br>
*The RFID module that I have has loose pins. So don't mind it in the video.*  
