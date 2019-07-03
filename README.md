# AmiiboArduino

I have been keeping up to date with the amiibos that I currently own.  
I have modified the original software, https://github.com/ModusPwnin/Interactive-Amiibo-Stand, to read the unique ID that each amiibo has.  
This has allowed me to make different songs for amiibos that have the same name but from a different game.

I have also posted the write/dump files I use that work with the device if the Adafruit guide is followed during build.  
I like to make my own custom amiibos that can be read from this device so these are required for me to make them.

I ended up not converting all the if/else statements into a switch statement in the code because space is an issue.  

Any of the files uploaded here can be loaded directly onto the arduino.

Original post can be found here: https://imgur.com/a/HaJBy

You will need:
1) Arduino Uno - http://www.arduino.cc/en/Main/arduinoBoardUno 
2) Adafruit Wave Shield - http://www.adafruit.com/product/94 *You will also need to download the waveHC library https://code.google.com/p/wavehc/ 
3) Adafruit NFC/RFID Shield - http://www.adafruit.com/product/789 *You will also need to download the NFC shield library https://github.com/adafruit/Adafruit_NFCShield_I2C 
4) An SD card Speakers with a 1/8" jack (Aux cable)

I followed the build process posted by Adafruit: https://learn.adafruit.com/babel-fish/overview

The Wave Shield can only play Wave files that are 16 bit, and have a 22kHz sample rate, so you will need to do some converting.
I use Audacity to do all of the mixes, which has taken me a very long time to make everything.
Also file name length can be an issue, sometimes the arduino will not read a file if the name is too long.
