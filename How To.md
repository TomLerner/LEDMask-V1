<h1>How To Create Your Own LED Mask</h1>

<h2>Project Background:</h2>

I got inspired to develop this project after seeing a year old post on Reddit’s Arduino sub-reddit by [/u/l30](https://www.reddit.com/u/l30). At that point I had no experience with micro-controllers or electronics and it’s been years since I’ve done any programming, however /u/l30’s engagement in the comment section, fielding questions on how he created his mask, gave me a sense that I could do it myself.

To create a foundation I decided to purchase the [“Arduino Starter Kit for beginner”](https://www.amazon.com/gp/product/B009UKZV0A/ref=ppx_yo_dt_b_search_asin_title?ie=UTF8&psc=1). The book explained the basics of the electronics, provided a good way to refresh my programming skills, and taught me how to create an electrical circuit board, which was my biggest concern starting out.

As I felt ready to develop my own mask, I reached out to /u/l30 and asked for some advice. He was able to point me out to a tutorial developed by [Armaiz Adenwala](https://armaizadenwala.com/blog/how-to-create-a-led-rave-mask-using-arduino/) demonstrating how to build his own version of a mask with schematics and code included. 

Two areas I did not have much guidance on and had to learn as I went. Assembling the mask itself and soldering the electronics. YouTube videos were helpful in understanding the basics of soldering but the only way I was able to see improvement is by putting more hours into it and varying in my approaches until I find the best fit for the soldering task.

As for assembling the mask it took putting it together, taking it apart and putting it together a second time to find the most suitable approach.

Below I’ll discuss each part of the development to provide a useful guide for others who want to create their own version.


<h2>Hardware:</h2>

[Arduino Nano ATmega238P](https://www.amazon.com/gp/product/B07G99NNXL/ref=ppx_yo_dt_b_asin_title_o04_s00?ie=UTF8&psc=1)

[WS2812B LED](https://www.amazon.com/gp/product/B07FVR6W71/ref=ppx_yo_dt_b_asin_title_o04_s01?ie=UTF8&psc=1) flexible strip with waterproof silicon cover

[PCB Board](https://www.amazon.com/gp/product/B07FFDFLZ3/ref=ppx_od_dt_b_asin_title_s01?ie=UTF8&psc=1) that I resized to fit the project box

[10K ohm Potentiometer](https://www.amazon.com/gp/product/B07Z913WMK/ref=ppx_yo_dt_b_asin_title_o06_s00?ie=UTF8&psc=1) for brightness control

[Momentary Push Button](https://www.amazon.com/gp/product/B07XXLHLT6/ref=ppx_yo_dt_b_asin_title_o08_s02?ie=UTF8&psc=1) for animation control

[470 ohm Resistor](https://www.amazon.com/gp/product/B07HDFBR2P/ref=ppx_yo_dt_b_search_asin_title?ie=UTF8&psc=1) for LED strip

[10k ohm Resistor](https://www.amazon.com/EDGELEC-Resistor-Tolerance-Resistance-Optional/dp/B07HDGX5LM/ref=sr_1_2_sspa?dchild=1&keywords=10k+ohm+Resistor&qid=1587677051&s=industrial&sr=1-2-spons&psc=1&spLa=ZW5jcnlwdGVkUXVhbGlmaWVyPUFXTUpKUjRZOEExV0gmZW5jcnlwdGVkSWQ9QTA2MDg2NTk3M0lXUzk4NUVZTiZlbmNyeXB0ZWRBZElkPUEwNTA4MTk0MUNLVktaRVBaUFdWNyZ3aWRnZXROYW1lPXNwX2F0ZiZhY3Rpb249Y2xpY2tSZWRpcmVjdCZkb05vdExvZ0NsaWNrPXRydWU=) for push button 

[100uF 25V Capacitor](https://www.amazon.com/flashtree-10pcs-Radial-Electrolytic-Capacitor/dp/B084ZMZSYH/ref=sr_1_3?dchild=1&keywords=100uF+25V&qid=1587677075&s=industrial&sr=1-3) for potentiometer

[24 AWG solid wire](https://www.amazon.com/gp/product/B07V1D82HM/ref=ppx_yo_dt_b_asin_title_o01_s00?ie=UTF8&psc=1) for most connections

[20 AWG flexible wire](https://www.amazon.com/gp/product/B07G844GCY/ref=ppx_yo_dt_b_asin_title_o03_s03?ie=UTF8&psc=1) for connection cord

[Battery Holder](https://www.amazon.com/gp/product/B079KTLMFW/ref=ppx_yo_dt_b_asin_title_o04_s04?ie=UTF8&psc=1) for 3 x 1.5V AA batteries with On/Off switch

[Project Box](https://www.amazon.com/gp/product/B07F462RYR/ref=ppx_od_dt_b_asin_title_s02?ie=UTF8&psc=1) (80 x 50x 26 mm)

[Two](https://www.amazon.com/gp/product/B072PCQ2LW/ref=ppx_yo_dt_b_asin_title_o03_s00?ie=UTF8&psc=1) [Types](https://www.amazon.com/gp/product/B01DZ8AR1U/ref=ppx_yo_dt_b_asin_title_o02_s00?ie=UTF8&psc=1) of heat shrink tubing

[Airsoft Face Mask](https://www.amazon.com/gp/product/B07Q48JBXW/ref=ppx_yo_dt_b_asin_title_o04_s02?ie=UTF8&psc=1)

[White Plastic Film Diffuser](https://www.amazon.com/gp/product/B00XJT7N9A/ref=ppx_yo_dt_b_asin_title_o01_s00?ie=UTF8&psc=1) for mask cover


<h2>Code:</h2>

The full code is available here:
[“LEDMask.ino”](https://github.com/TomLerner/LEDMask-V1/blob/master/LEDMask.ino) is the main executable and [“constants.h”]((https://github.com/TomLerner/LEDMask-V1/blob/master/constants.h)) holds the patterns and palettes. Additionally the FastLED library and PushButton library are used

The foundation of the code is based on Adenwala’s work and his ```pattern()``` function [renamed to ```customPattern()``` in my code] is used in half of the available animations and definitely the “cooler” looking ones. The basics of mapping IDs to each LED for creating a pattern remains the same as well as the idea of connecting the IDs to a color bridge. Adenwala does a terrific job of explaining how that works in his How To guide.

To adjust the code to my project I’ve made a number of changes:

- Allow for a serpentine wiring of the LED rows. For this two functions were added. ```ConvertIndex()``` to perform a check if the currently addressed LED requires flipping of its ID and ```FlipIndex()``` to perform the flip.

- Support multiple pattern arrays at once and the ability to switch between them. I’ve created a unique function for each pattern animation that calls ```customPattern()``` and used a different Pattern Array from those declared in constants.h.

- Move away from declaring color arrays, which I quickly realized takes a lot of memory and limits the creative options, to instead use the Color Palette options built into the FastLED library. Having an huge existing repository of palettes solidified the choice.

Using the class ```TProgmemRGBGradientPalettePtr``` I created a unique array of chosen palettes for each available pattern used in ```customPattern()```. The palettes were sourced from cpt-city and over 100 were tested on 6 animation patterns. The list was reduced to a library of 41 with a curated list for each pattern. All the palettes are declared in constants.h.

Applying the palette is done in this call ```leds[convertedI] = ColorFromPalette(currentPalette, patternColors[color] * 16, 255, currentBlending);``` I’m using jumps of 16 on each palette, even though the separation between the declared values of the palette may not equal to jumps of 16, because of the data structure of the palettes and finding that this creates the best results.

With the palettes already having a gradual gradient I didn’t need the ```getColorFade()``` part from Adenwala’s code and removed it.

In the call function of each unique pattern that calls on ```customPattern()``` [e.g. ```customScrollingRowPattern()``` ] there’s a function that randomly chooses between the available palettes every 10 seconds.

- Add preset animations that are part of the FastLED Library. I’ve decided to use: ```rainbowWithGlitter(), confetti(), sinelon(), bpm() , juggle()```. Those were just copied into the code as is along with ```EVERY_N_MILLISECONDS( 12 ) { gHue++; }``` into the main loop.

- To have the option to switch between all the available animations including all patterns in the custom animation and all preset animation for FastLED Library I’ve created a class called ```SimplePatternList``` with an array gPatterns that holds a list of all animation function calls. When the index in gPatterns changes a different function is called in the main loop.

- To control the switching between animations I’ve added a momentary push button. After a lot of research I’ve decided to go with PushButton library developed by kristianklein. I’m using three checks. Single Press to move forward one item on the list of animations, Double Press to move one animation back and Long Hold to change into random mode. As I’m checking for all three events at the same time every Double Press also detected a Single Press event. To compensate, a double press event moves the index by -2, resulting in a single step back.

- Randomizing between the animations is achieved using a Boolean called ```randomPattern```. It starts false but on a Long Hold event it’s set to true. An if check in the main loop checks the bool and when true randomizes between the available list of animations. When a single press event is triggered the boolean turns to false.

- I wanted to be able to control the brightness of the LED. I’ve added a simple check on a potentiometer and map it to values between 100% and 20%. Lower than 20% is barely visible through the diffuser.

- Both the Push Button and Potentiometer require a minimum expected response time from interaction to reaction. Unfortunately the code used for customAnimation runs through multiple for() loops on multiple arrays, slowing down the reaction significantly. To assist, there are two separate calls for ```potentialBrightness()``` and ```myButtonIfCheck()```. One inside the main loop and the second inside ```customPattern()```.

- To make it easy to develop patterns for ```customPattern()``` I’ve developed a simple excel spreadsheet with two tabs that work together.
In (edit) I’m able to have a visual approximation for the shape of the mask and layout of LEDs as I assign the IDs for the pattern.
(code) updates automatically based on (edit) and provides the layout in the correct format for the code, allowing for a simple selection of range and then copy/paste into constants.h.

- To make it easy to curate and manage the palettes I assigned to each customPattern I created a simple spreadsheet for tracking.

<h2>Electronics:</h2>

The full schematic I’ve designed is available HERE.

Adenwala provides the basic connection for Arduino/LED/Battery Pack. Instructions for Push Button are available on Arduino website as well as Potentiometer.

Putting everything together only meant ensuring each separate component is correctly connected to the power circuit.

Constructing the LED grid was a difficult task. To use Adenwala’s code and minimize the number of separate pieces I’ve decided on a horizontal layout. In future attempts I will try vertical slices. The first step is a lot of measuring and re-measuring how many individual strips can fit into the mask, how long each one would be, the distance between them, etc. My approach was to start from the widest area to the narrowest which also meant going from top to bottom. Finding if my widest point best fits an odd or even number of LEDs I decided the length of my first strip. From there I’ve continued down, trying to fit the next row with a length of 1 less LED. I’ve eventually found that a total of 7 rows can fit tightly and opted to proceed with 6.

From experience I’ve learned that when cutting the LEDs it’s best to have extra space on the soldering points which requires sacrificing an LED between every cutting of the strip. To create my 6 rows I had to cut out 5 LEDs with hardly any solder points that cannot be used.
The type of LED I got has silicon coating applied along it for waterproofing. This meant removing a small section of the coating just above the solder points. This was done with a precision cutting tool (like x-acto knife).

Next step is to solder the LED strips together. First, I tapped the strips to a piece of cardboard using electrical tape with the diodes facing the cardboard, making sure all lines are centered, equally spaced and fit in the height of the mask. Now I had the basic layout holding together on its own. I then cut the cardboard close to the edges of the LED strips for each access to the solder points. Now it’s easy to solder the strips together.

The distance between each connection is almost identical across the mask, however as I’m working with a serpentine shape where the + cable will run the outside of the 3 connections, on the right side it will run the inside part. This just means that the length of the + cable on the left is the same as the - cable on the right and vice versa. The data cable being in the middle is always the same length on both sides. Here it’s important to use a solid wire, not a flexible one. This will help to hold the connections solid when applying the LED strips.

Before soldering the strips I cut small sections of heat shrink tubes, fitted over the LED strips and then after the solder, I sealed the connections on both sides. Not only will this assist with waterproofing the section of the LED that I stripped the silicon from but also provide extra strength to the wire by the solder point when we bend it later.

For creating an electrical board I highly recommend creating a design and purchasing custom printed boards from a manufacturer if you don’t have the option to print one yourself. As this was my first project I attempted to create the connections using wires on the board and while that definitely works it’s not each to solder jumping connections between holes on the board.

It’s also very important to measure and double measure the project box you will need to support the board you are building on. Not only the fitting space but also the distance for the mounting holes and the vertical space for mounting push button to the boxe’s front panel.

Placing the push button and potentiometer on the front panel was extremely easy. I first drilled two small holes into the plastic cover and then increased the size as needed for each input. Using a nut they were secured into place.

Two additional holes were drilled into the top of the project box to pass the 3 wires of the LED and 2 wires of the Battery Pack. For the LED wires I’ve decided to have a connection point close to the project box with a short cable and connection point on the outside. I’ve placed a heat shrink protector on the outside and hot glue on the inside to seal the hole. The same was done with the battery pack. The battery pack was then hot glued to the back side of the project box, with the switch button accessible, to create a single unit.

Soldering the board, input devices, LED and power together was tricky as all components had to be close to one another, so using some gripper with clippers to help hold everything while soldering is very recommended.

<h2>Mask:</h2>

The mask uses a plastic diffusing material in front of the LED strips to help spread the light and create a richer color effect. After several attempts I settled on an approach that works best for me on how to create and fit the screen.

First, using an A4 paper, cut it into a square slightly bigger than half the mask, from the center point to the outside of the mask, leaving sufficent room outside the borders of the mask. Next, start bending the cut paper into the curvature of the mask, only trying to fit the paper into half the mask. While bending the paper and fitting it in, apply tape on a few points to help hold it in place. When fitting is sufficient (it will never be perfect) trace the paper from the outside of the mask. Remove the A4 paper, straighten it and cut the shape to be exact based on the marked line. Tape the A4 paper to the plastic diffuser and cut 2 identical pieces. Those will be the left and right sides of the mask. There will be a small gap in the center missing between the two that will be fitted later.

Starting with one of the sides, align the new cut to the mask and bend into the curvature. After bending and holding for a bit the plastic will start retaining some of the new shape. Using hot glue and the helping hands of a friend start gluing the plastic to the edges of the mask. Trace a section of the edge, apply pressure to the diffuser and mask and hold for 10 seconds. Keep tracing the edge until half the mask is covered. I found that starting furthest from the center mask and working inwards both sides at the same time helps keep it as straight as possible. Finish applying the second half of the mask. Now there will likely be a small gap between the two sides in the center as well as a small area of overlapping. If possible, cut the overlapping second on one side to minimize it. Then cut a piece just slightly bigger than the size of the missing area and super glue to both sides, covering the hole. Use a thin layer of super glue as it can affect the diffusion of the light.

Next is placing the LEDs on the mask. Remove the strips from the cardboard but keep them together with the help of the electrical tape, add more if needed. Now take the first row, align the middle LED to the center, pushing it into the curve of the mask, and find where the left and right ends fall. Both ends should have a heat shrink tube already attached to them. Apply super glue (while wearing gloves) to each side and attach them to the mask with pressure. The glue on both sides should provide enough support to hold the curve of the LED strip without requiring extra glue points in the middle of the strip. Proceed with the same process on the next LED strip.

During this stage a lot of pressure will be applied on the LED strips and the solder points. Because of that I recommend having the LEDs turned on an animating while applying them to the mask so if a connection fails at any point it can be immediately noticed and fixed.

With all the LEDs attached to the mask the functionality is complete, the final steps are for comfort. I used a thin piece of flexible packaging foam to trace the full shape of the mask. I cut the foam and applied it on top of the LEDs with hot glue to the edge of the mask. Using the same foam I cut an extra small section and fitted it into the note curve for extra cushioning. Using a slightly harder foam I cut bigger round pieces and glued them to the sides as supports for the cheekbones which will hold most of the pressure of the mask on the face.

Finally to make the mask comfortable to touch on the face I cut a piece of white shirt to the approximate size of the mask, glued it using hot glue and then cut around. I left extra material so that I can bend it inwards and hot glue onto itself, leaving less seams for fabric to tear.

The connection cord between the first LED row and the electrical box was created using a flexible wire cut to measure. The wire is attached to the mask with each solder point covered with a small heat shrink cover and then all 3 wires with a long piece of heat shrink for durability protection.

<h2>Future improvements:</h2>

- [ ] Add a mic to detect the voice of the wearer and adjust the brightness to their speech, making the mask animate in response to the voice of the wearer.

- [ ] Add a second push button to manually control palette rotation.

- [ ] Improve the customPattern() code to run more efficiently so additional calls for input checks are necessary.

- [ ] Change the structure of how Palettes are stored so instead of a unique list for each Pattern declaring the palette by name there’s a single library and the index ID of the chosen palettes are called by the pattern.

- [ ] Re-examine how palettes are used so that moving through the gradient doesn’t have to happen in jumps on 16 steps.

- [ ] Improve the push button code so double press doesn’t read as a single press event as well.

- [ ] Use a Hook-and-loop fastener for attaching the soft fabric to the mask (instead of hot glue) so it can be removed, washed and reapplied.

- [ ] Find a different protecting sleeve for the mask cable cord, as just a heat shrink tube isn’t best suited for the job.


