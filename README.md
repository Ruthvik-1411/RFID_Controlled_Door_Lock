# RFID_Controlled_Door_Lock
<b> About</b><br>
   Arduino based RFID door lock system is secure, quick and contactless compared to other mechanisms. It is compact and
   easy to make. It can work in any environment and is being used at many places like offices, hospitals which require quick and efficient access while being secure.
   RFID tags are simple to carry and blend in the daily items. The logic behind it being that efficient is 
   <a href="https://github.com/Ruthvik-1411/RFID_Controlled_Door_Lock/blob/main/RFID%20logic.jpg">RFID logic</a>.<br><br>
<b> Components Required</b>
 <li> Arduino Board<br>
 <li> Servo motor
 <li> MFRC522 RFID Module with tags
 <li> 16x2 LCD Display
 <li> Breadboard and Jumper wires
 <li> 1xRed Led, 1xGreen Led<br><br>
    <b> Principle and Working</b><br>
    The RFID reader consist of a radio frequency module, a control unit and an antenna coil which generates high frequency electromagnetic field. On the other hand, the tag is usually a passive component, which consist of just an antenna and an electronic microchip, so when it gets near the electromagnetic field of the transceiver, due to induction, a voltage is generated in its antenna coil and this voltage serves as power for the microchip.<br>Now as the tag is powered it can extract the transmitted message from the reader, and for sending message back to the reader, it uses a technique called load manipulation. Switching on and off a load at the antenna of the tag will affect the power consumption of the reader’s antenna which can be measured as voltage drop. This changes in the voltage will be captured as ones and zeros and that’s the way the data is transferred from the tag to the reader.<br>There’s also another way of data transfer between the reader and the tag, called backscattered coupling. In this case, the tag uses part of the received power for generating another electromagnetic field which will be picked up by the reader’s antenna.<br><br>
    
<li>First the Built in examples like Dumpinfo, firmware_check should be used to check if everything works properly.<br>
<li>After that the connections should be made accordingly and after uploading the code everything should work properly.
<li>While writing the code download this library if needed (optional) <a href="https://codeload.github.com/miguelbalboa/rfid/zip/refs/heads/master">RFID master</a>
<li>The RFID connections are as shown:<br>
   &nbsp;&nbsp;&nbsp;&nbsp;<b>MFRC522&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Arduino Uno</b><br>
   &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;RST &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;9<br>
   &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;SDA(SS)&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;10<br>
   &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;MOSI&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;11<br>
   &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;MISO&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;12<br>
   &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;SCK&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;13<br>
If everything is good then the dumpinfo code returns some data with 0s 1s and some characters in big blocks ranging from 15 to 0.<br>
   DOOR LOCK : <a href="https://drive.google.com/file/d/1Ei_IVKZhGhDtJf-_boprRYavVWyBphMw/view?usp=sharing">video link</a>

   
