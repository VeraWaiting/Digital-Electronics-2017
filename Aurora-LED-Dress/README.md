# Aurora Dress

### Demostration Videos

Final demostration at the Interface Show: (I wore it.)

https://www.instagram.com/p/BTx_3OsFZwy/?taken-by=vera_wei_wang&hl=en

Testing different patterns: (on a female body model)

https://www.instagram.com/p/BTUeVlJlBUN/?taken-by=vera_wei_wang&hl=en

### Introduction

Aurora Dress is a fantastical dress on which 44 LEDs blink in different colors and patterns according to the different movements of the wearer. It is a combination of art and science, or design and technology, to stimulate inspirations, excite imaginations, and create dreamy interactive experiences for users.

An absolute orientation sensor attached to the dress is used to detect Euler angles, accelerations, angular velocities, and angular accelerations of the wearer in different directions. Then an Arduino Uno processes these data and controls the blinking of 44 RGB Smart neoPixel LEDs to create different patterns: rainbow-like aurora for staying static, theatre chasing for jumping, wiping for spinning, etc.

With the development of science and technology, wearable technology is becoming more and more popular. As are LED dresses. We have figured out many ways to make a dress blink, like sewing LEDs on to a dress, attaching fibre optics to a dress, even making cloth itself glow. But all of these existing LED dresses blink just by themselves and have no interaction with the wearer. I wanted to explore the relationship between humans and wearables, thus I designed this Smart Blinking Dress, which blinks in a more meaningful way by discovering and reflecting the wearer in every of his/her movements.


### Technology

- An BNO055 absolute orientation sensor is used to detect the movement of the wearer.
- 44 Adafruit Smart neoPixels are solded and sewed onto a dress. 
- New classes are written in Arduino to realize different patterns of the lights.

### Process

1. Sketch:

![led dress - sketch](https://cloud.githubusercontent.com/assets/23609156/23991460/b59e5536-09f6-11e7-823c-9412d0168fff.jpg)

2. Schematic:

![led dress - schemetic - 1](https://cloud.githubusercontent.com/assets/23609156/25797229/26a64536-3391-11e7-9e99-c477fc43e763.jpg)

3. Testing BNO055:

![img_5789 copy](https://cloud.githubusercontent.com/assets/23609156/25799101/9ea7a280-3398-11e7-963e-e156c27f9bc4.jpg)

4. Design the pattern (positions NeoPixels on the dress):

![design pattern](https://cloud.githubusercontent.com/assets/23609156/25799197/eb480b2a-3398-11e7-9431-abc9033c4cf9.jpg)

5. Sewing NeoPixels onto a piece of cloth

![img_5879 -](https://cloud.githubusercontent.com/assets/23609156/25799284/4fcbda40-3399-11e7-84ff-86fc7f6ce0de.jpg)

6. Soldering wires to connect NeoPixels

![img_5883 copy](https://cloud.githubusercontent.com/assets/23609156/25799305/5fb3fbcc-3399-11e7-87f8-2cb4d5101e5f.jpg)

7. Sewing the piece of cloth onto a dress

![img_5941 copy](https://cloud.githubusercontent.com/assets/23609156/25799349/855802b0-3399-11e7-90cf-d3854c064890.jpg)

8. Programming

<img width="674" alt="screen shot 2017-05-08 at 3 01 24 am" src="https://cloud.githubusercontent.com/assets/23609156/25799640/a97b024a-339a-11e7-8e0b-087eb5a086dc.png">

9. Sewing the BNO055 sensor, the Arduino Uno, and a power bank on the inside of the dress

I sewed the sensor at the dress's waist, instead of at its hemline, so that it can detect the movements of the wearer immediately.  

![img_6169--](https://cloud.githubusercontent.com/assets/23609156/25799830/7e837396-339b-11e7-974b-2c309c25e4d5.jpg)

10. Completed! Wear it to attend the Interface Show.

![img_6211](https://cloud.githubusercontent.com/assets/23609156/25800359/d9bdf73e-339d-11e7-9859-b699cbb973bb.PNG)

### Continuing

- Time-lapse photography
- Many people want it， so I'll try to reduce the cost and try mass production if I have chance.
