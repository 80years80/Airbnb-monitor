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

In the future the project will be optimized, and improved. One improvement is to just use one arduino and just commuicate with
Pi directly through the NRF attena's. Another improvement I plan to make is to graph the data and then send the file in the email.
