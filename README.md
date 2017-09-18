# Raspberry-Pi-LED-Control

This is simple code runs on Raspberry Pi 3 B to control LED bulb using C

Here are some GPIO numbering of Raspberry Pi 3!
![alt tag](https://github.com/junsujeong/Raspberry-Pi-LED-Control/blob/master/a-and-b-gpio-numbers.png)

I connected GPIO18 to 220 ohm resistor and anode(+), and connect GND to Cathode(-).

If you have connected all the wire, check if it works properly by echo

echo "18" > /sys/class/gpio/export /*set up GPIO18*/ 
echo "out" > /sys/class/gpio/gpio18/direction /*setting it to output*/
echo "1" > /sys/class/gpio/gpio18/value /*turn on the LED by setting the value to HIGH 1*/
echo "0" > /sys/class/gpio/gpio18/value /*turn off the LED by setting the value to LOW 0*/
echo "18" > /sys/class/gpio/unexport /*disconnect GPIO18*/

Running gpioLed.c

Running wiringLed.c

Hope it helped you!
