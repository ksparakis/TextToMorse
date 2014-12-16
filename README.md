TextToMorse
===========

This is a basic program I wrote for the raspberry pi, It makes a led blink the morse code of whatever text you input in.


How To Compile and Setup
--------------------
To compile simply type this into the terminal where the file is located:

gcc morse.c -o morse

To Use, Plug an led to gpio pin 17 of the Raspberry Pi

Example Commands
--------------------
./morse TEXTWITHNOSPACES

./morse "A string of words to be turned into morse code"


Code Design
------------
I designed my code to use a switch statement within a while loop for all letters in order to save complexity and time
with just using a bunch of if, if else, else statments. The reason I used a while loop is because the while loop will continue running untill it hits the null pointer of the array of characters allowing me to input any length of a word.

I from there created 4 classes to implement the code:

gpioW()     this writes a value of 0 or 1 to the GPIO pin

inletter()	sleeps the code for the according time when off interval inside a letter is needed.

dot() 	  	turns the light on and sleeps for the dot on time.

dash() 	  	turns the light off and sleeps for the time off time.


This removed the repetiveness of typing out all the commands for turning on and off the light and sleeping.
