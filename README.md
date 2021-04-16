# CarLights
I was asked how to connect an arduino to car brake and indicator (turn signal) lights so a string of LEDs could be used instead of the bulbs. In the video I talk about 3 ways in which you could do this using a Zener diode, Schottky diode or Optoisolator to change the 12V signals from the car to 5V Arduino-safe signals. Code and schemtics can be found in this repository.
## YouTube Video

[![Youtube video of the LED car lights](http://img.youtube.com/vi/gqaCwqRQ3gE/0.jpg)](https://www.youtube.com/watch?v=gqaCwqRQ3gE)

## Warning
This project is to be used for experimental and education purposes only. Using this setup on a road-going vehicle is not a good idea, as the reliability and brightness do not meet minimum legal standards.

## What do I need to make this?
- 5V Arduino (nano, uno etc)
- 5V addressable LED strip (e.g. WS2812B)
- 5V buck regulator module
- 3 x regular diodes (e.g. 1N4001 or higher rated if you have more LEDs)
- 3 x 5.1V Zener diodes **or** 3 x Schottky diodes (e.g. 1N5817)
- 6 x 10k resistors (1/8W, 1/4W, anything will work!)
- 3 x tactile push buttons (only needed for testing)
- Breadboard (for testing)
- Wire, connectors, solder, usual electronics stuff!
