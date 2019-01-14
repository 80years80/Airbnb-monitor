# Airbnb-monitor
Purpose of project is to made aware of potential conditions that could cause damage to the home while away from it.

This is achieved by using two arduino uno's, a raspberry pi 2B+, Si7021 humidity sensor, MSEQ-4 gas/smoke detector,
and two NRF24 attena's.

One arduino is an area where conditions are likely to occur that could damage the home, 
this then calculates if any concern is present and then transmits this status to another arduino via NRF24 attena's.
The second arduino uno is connected to the raspberry pi, a python script is run to check if any of the conditions are presesent.
If the condition is present long enough in the span of an hour the script will then enter a bash command to email the user about
what concerning conditions are present and should be checked up on.

This can send an email to the owner of the place, guests, as well as friends and neighbors who can check up on one's place
while they are away. 

------Future of Project------

New features:
Add a key dispener outside your door so your friend/neighbor/landlord can check on your place if you get an alert email. 
Will be 3D printed, the design will be at the top a narrow opening to drop the key back in. 
At the middle there will be a RFID scanner. The home owner will send a communication to enable RFID reading on the scanner.
At the bottom of the scanner will be bowl to be disgusied as a birdfeeder. It is important for the key dispener to blend in,
so no one tries to break the key out given the idea for this project is to leave your home alone for a potentially long time.

*Note the RFID scanner should not always be enabled as forging an RFID master key is too easy. 


Optimization plans:
The Raspberry Pi and the Arduino can communicate directly through the NRF24 attena's. This is so we do not need to have the
second arduino connected to the Pi just to recieve the data.
