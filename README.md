![image](https://github.com/yifan1207/Automated-Bike-Turning-Light/assets/117659507/8a1ce39b-47ff-44ab-8e80-f6affe6a5464)

**Automated-Bike-Turning-Light**
An automated turning detection and display system for bikes.
In daily life, bicycles are a common means of transportation for people. Since bicycles do not have Turning Lights often found in motor vehicles, it is diﬃcult to inform nearby pedestrian vehicles when turning and changing travel speed, so traﬃc accidents can easily occur in such situations. As an avid cyclist myself, I designed a bicycle steering alert system is developed for the scenario of bicycle steering. 
The device is mainly controlled by Arduino, and with the help of Bluetooth wireless transmission technology, the steering and auxiliary data collected by the upper computer, such as steering instructions, speed, and driving intentions, are sent to the lower computer for processing. The steering information is then displayed on a high-powered LED digital dot matrix screen, and the steering information is prompted by a voice announcement device. 

Watch our demonstration video! https://www.bilibili.com/video/BV1VZ4y1D77w/?p=1&share_medium=ipad&share_plat=ios&share_source=COPY&share_tag=s_i&timestamp=1653965370&unique_k=EDYhOYR
Post on Arduino Project Hub: https://projecthub.arduino.cc/andyz1207/automated-bike-turning-light-e0a11a


**Detection System**

First, as the user opens the display screen and the turning detection system, the two Bluetooth devices in both systems will automatically pair by finding a common frequency previously set by us. After pairing, the turning detection system’s first precedence would be to collect the input from the three-position switch where the user manually controls the direction arrow display with the buttons I, 0, II corresponding to a left, forward, and left motion or turning direction. However, if the input from the switch is zero of the middle position, indicating a forward motion, or if the bike experiences a change of direction from >15 degrees to <-15 degrees or vice versa then the system would operate under our innovative automated turning detection system which is of the second precedence. The automated turning detection detects the heading of the bike by using the variable resistor which is connected to the front intersection node of the bicycle using a synchronizing line. As the bicycle head is turned, the resistance provided by the variable resistor is also going to change correspondingly. If the resistance detected is smaller than 450 ohms then the bicycle is going to categorize it as a right turn, where the heading of the bicycle is 15 or more degrees to the right of the vertical position. And if the resistance detected is more than 550 ohms then the bicycle is going to categorize it as a left turn, where the heading of the bicycle is 15 or more degrees to the left of the vertical position. 
![image](https://github.com/yifan1207/Automated-Bike-Turning-Light/assets/117659507/5684530f-9f1f-4f6d-9c60-1d31dbc75431)
![image](https://github.com/yifan1207/Automated-Bike-Turning-Light/assets/117659507/77eea1dc-fa1f-4ec0-8189-fd25b575079e)
![image](https://github.com/yifan1207/Automated-Bike-Turning-Light/assets/117659507/9fec83d8-5a22-4688-9936-d5100d4d2cd9)



**Display System**

Now with the turning data collected, we share the stored motion states in terms of integers from 1-3 through our wireless Bluetooth transmissions with the embedded system of our display screen. Then the display screen system takes the current state of the bicycle and compares it to the previous state of the bicycle; if they are different, the display system would opt to change the display of arrows on the screen followed by a sound announcement, this process happens at a rate of 10Hz (10 times per second). 
First, the display system produces sound announcement by evaluating the motion sate and sending the corresponding digital data stored in the system to the sound module. Then the sound module will convert the digital data back to analog data through DAC ( D igital-to- A nalog C onversion). The sound produced by the module describes the motion state of the biker such as “left turn, be careful, ” and serves as an alert to other pedestrians or vehicles who cannot see the display screen of the bike or are physically blind. 
Then, to change the display of turning arrows on the screen we utilized our innovative technology of graphical decoding. To achieve. Graphical decoding, we implemented the LED control method where we controlled each LED light’s brightness and color individually by assigning all of them a unique ID. In order to display the LED direction icons, our solution divides each arrow icon into four parts and displays each part on the corresponding 4 smaller LED board that, together, makes our display screen. After receiving a motion state update, the algorithm takes the corresponding graphical arrow icon and overlaps the icon onto the display screen. Then the lights overlapping the graphics will be lit by through function control to achieve the display effect. In terms of programming language implementation, the brightness and color of each light are determined by setting the RGB values of each LED lamp. 
When displaying the motion state of the biker, the display board flashes in an irregular pattern. This is done by the algorithm reseating all the lights to colorless [RGB (0, 0, 0)] then the program waits for a randomly generated amount of time ranging from 50ms to 200ms. Finally, the algorithm illuminates all the lights corresponding to the arrow and waits for 50ms to 200ms. This process repeats indefinitely for all motion states to make the biker more recognizable to other pedestrians or vehicles. Since we are using a high-powered dot matrix display screen each light bulb can shine up to 15 lumens which is around the brightness of a smartphone’s backlight. 
Our product is also water-resistant, able to withstand light rain (< 2.5 mm [0.098 in] per hour) for more than 8 hours.
![image](https://github.com/yifan1207/Automated-Bike-Turning-Light/assets/117659507/c5f75f0d-1ed2-4c4f-8471-93fb438b6962)
![image](https://github.com/yifan1207/Automated-Bike-Turning-Light/assets/117659507/afd350bb-02a1-4038-adce-4c85094edb88)


**Why Project?**

Turning Helper is unique because it is a service that contributes to the battle against non-motor vehicle accidents, rather than a product. The final product that is produced through Turning Helper is unlike any other existing product. The current solution to deal with non-motor vehicle accidents are traffic policies and manual turning lights. The Turning Helper features the innovative automated turning system and a 32*32cm LED display board that both presents the motion of the biker and also acts as a flash light to increase visibility of the biker. This idea is revolutionary and unique, as the Turning Helper is a combination of innovative techniques and already proven techniques to prevent non-vehicle accidents mounted onto one produce that is easily assembled and compatible with backpacks, vests, and insulated delivery cabinets. 
![image](https://github.com/yifan1207/Automated-Bike-Turning-Light/assets/117659507/1ed1375e-2be2-4e79-a9a1-58e503fd4486)
![image](https://github.com/yifan1207/Automated-Bike-Turning-Light/assets/117659507/a654f6d4-4db5-4fbf-96d3-79687c7edd2a)
![Uploading image.png…]()


