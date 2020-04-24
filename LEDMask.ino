#include <FastLED.h>
#include <PushButton.h>

FASTLED_USING_NAMESPACE

//LED
#define DATA_PIN    A5
//#define CLK_PIN   4
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
#define NUM_LEDS    75
CRGB leds[NUM_LEDS];

#include "constants.h"

#define FRAMES_PER_SECOND 120

// Push button for Pattren Animation Cycle
#define buttonAnimationPin   A0
PushButton myButton(buttonAnimationPin);

//Potentiometer for Brightness
#define potBrightnessPin      A2                       // analog pin used to connect the potentiometer

CRGBPalette16 currentPalette;
TBlendType    currentBlending;

// --------------------------------------------------------------------------------------------------------------------------- SETUP EXECUTABLE ----------------------
void setup() {
  randomSeed(analogRead(0));

  delay(1000); // 1 second delay for recovery

  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip); // tell FastLED about the LED strip configuration

  pinMode(buttonAnimationPin, INPUT); // initialize the pushbuttons pin as an input for animation cycle

  Serial.begin(9600); // Allow Serial Monitor for debugging
}
// ------------------------------------------------------------------------------------------------------------------------------- END SETUP ------------------------

// List of Patterns to cycle through.  Each is defined as a separate function below.
typedef void (*SimplePatternList[])();

// Decleration of all Animation Functions
SimplePatternList gPatterns = { customBigVPattern, customTrianglesPattern, customCirclesPattern, customOutwardsWingsPattern, customScrollingRowPattern, customScrollingColumnPattern, customCrossLinesPattern, rainbowWithGlitter, sinelon, confetti, juggle,  bpm};
//                                      0                     1                      2                        3                       4                           5                             6                      7             8          9       10      11

#define ARRAY_SIZE(gPatterns) (sizeof(gPatterns) / sizeof((gPatterns)[0]))
uint8_t gCurrentPatternNumber = 0;        // Index number of which pattern is current

// List of Palettes to cycle through. All defined below.
extern const TProgmemRGBGradientPalettePtr gGradientPalettes[];
//extern uint8_t gGradientPalettesCount;
uint8_t gCurrentPaletteNumber = 0;        // Current number of available palettes the 'playlist' of color palettes

uint8_t gHue = 0;                         // rotating "base color" used by many of the patterns

bool randomPattern = false;               // Boolean for randomizing patterns state

// ---------------------------------------------------------------------------------------------------------------------------MAIN EXECUTABLE ----------------------

void loop()
{
  
  myButton.update();
  myButtonIfCheck();

  gPatterns[gCurrentPatternNumber]();                                                           // Select pattern based on index number from gPatterns list

  if (randomPattern == true) {                                                                  // Check if Random Pattern is set to true
    EVERY_N_SECONDS( 3 ) {                                                                      // Every n seconds
      gCurrentPatternNumber = random(0, ARRAY_SIZE( gPatterns));                                // Change to random pattern
    }
  }

  potentialBrightness();                                                                        // Check potentiometer for brighness change

  EVERY_N_MILLISECONDS( 12 ) {                                                                  // Change Hue base color every X milliseconds
    gHue++;                                                                                     // slowly cycle the "base color" through the full spectrum
  }

  FastLED.show();                                                                               // Refresh the LEDs on the strip
  FastLED.delay(1000 / FRAMES_PER_SECOND);                                                      // insert a delay to keep the framerate modest

}

// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX MAIN END XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX


// ---------------------------------------------------------------------------------------------------- INPUT CONTROLS FUNCTIONS START ----------------------------

// Check for Pattern Button input
void myButtonIfCheck()  {
  if (myButton.isDoubleClicked())                                                                 // Double-click event
  {
    gCurrentPatternNumber = (gCurrentPatternNumber - 2) % ARRAY_SIZE( gPatterns);                 // Move current pattern two options back (goes two because single click event is always initiated. -2 + 1 = -1 )
  }
  if (myButton.isClicked())                                                                       // Click event
  {
    randomPattern = false;
    gCurrentPatternNumber = (gCurrentPatternNumber + 1) % ARRAY_SIZE( gPatterns);                 // Move current pattern one option forward
  }
  if (myButton.isHeld())                                                                          // Hold/long push event
  {
    randomPattern = true;                                                                         // Move current pattern one option forward
  }
}

// Brightness Check using Potentiometer
void potentialBrightness() {
  FastLED.setBrightness(map(analogRead(potBrightnessPin), 0, 1050, 20, 100));               // scale the numbers from the potential value (20 - 100)
}


// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX INPUT CONTROLS FUNCTIONS END XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

// --------------------------------------------------------------------------------------------- ANIMATION FUNCTIONS START ----------------------------

// ----------------------- Preset animations -------------------------

// Pattern Animation - Preset: Rainbow
void rainbow()
{
  // FastLED's built-in rainbow generator
  fill_rainbow( leds, NUM_LEDS, gHue, 5);
}

// Pattern Animation - Preset: Rainbow w/ Glitter
void rainbowWithGlitter()
{
  // built-in FastLED rainbow, plus some random sparkly glitter
  rainbow();
  addGlitter(80);
}

// Pattern Animation Add-on - Preset: Glitter
void addGlitter( fract8 chanceOfGlitter)
{
  if ( random8() < chanceOfGlitter) {
    leds[ random16(NUM_LEDS) ] += CRGB::White;
  }
}

// Pattern Animation - Preset: Confetti
void confetti()
{
  // random colored speckles that blink in and fade smoothly
  fadeToBlackBy( leds, NUM_LEDS, 10);
  int pos = random16(NUM_LEDS);
  leds[pos] += CHSV( gHue + random8(64), 200, 255);
}

// Pattern Animation - Preset: Sinelon
void sinelon()
{
  // a colored dot sweeping back and forth, with fading trails
  fadeToBlackBy( leds, NUM_LEDS, 20);
  int pos = beatsin16( 13, 0, NUM_LEDS - 1 );
  leds[pos] += CHSV( gHue, 255, 192);
}

// Pattern Animation - Preset: BPM
void bpm()
{
  // colored stripes pulsing at a defined Beats-Per-Minute (BPM)
  uint8_t BeatsPerMinute = 80;
  CRGBPalette16 palette = PartyColors_p;
  uint8_t beat = beatsin8( BeatsPerMinute, 64, 255);
  for ( int i = 0; i < NUM_LEDS; i++) { //9948
    leds[i] = ColorFromPalette(PartyColors_p, gHue + (i * 2), beat - gHue + (i * 10));
  }
}

// Pattern Animation - Preset: Juggle
void juggle() {
  // eight colored dots, weaving in and out of sync with each other
  fadeToBlackBy( leds, NUM_LEDS, 20);
  byte dothue = 0;
  for ( int i = 0; i < 8; i++) {
    leds[beatsin16( i + 7, 0, NUM_LEDS - 1 )] |= CHSV(dothue, 200, 255);
    dothue += 32;
  }
}

// ----------------------- Custom animations calls --------------------

// Pattern Animation - Custom Big V
void customBigVPattern() {
  currentPalette = gBigVPalettes[ gCurrentPaletteNumber ];
  EVERY_N_SECONDS( 10 ) {
    gCurrentPaletteNumber = random(0, gBigVPalettesCount);
  }
  customPattern(bigVPattern, scrollingColors, false, 3, 16);
}

// Pattern Animation - Custom Triangles
void customTrianglesPattern() {
  currentPalette = gTrianglesPalettes[ gCurrentPaletteNumber ];
  EVERY_N_SECONDS( 10 ) {
    gCurrentPaletteNumber = random(0, gTrianglesPalettesCount);
  }
  customPattern(trianglesPattern, scrollingColors, false, 2.5, 16);
}

// Pattern Animation - Custom Circles
void customCirclesPattern() {
  currentPalette = gCirclesPalettes[ gCurrentPaletteNumber ];
  EVERY_N_SECONDS( 10 ) {
    gCurrentPaletteNumber = random(0, gCirclesPalettesCount);
  }
  customPattern(circlesPattern, scrollingColors, false, 2, 16);
}

// Pattern Animation - Custom Outwards Wings
void customOutwardsWingsPattern() {
  currentPalette = gOutwardsWingsPalettes[ gCurrentPaletteNumber ];
  EVERY_N_SECONDS( 10 ) {
    gCurrentPaletteNumber = random(0, gOutwardsWingsPalettesCount);
  }
  customPattern(outwardsWingsPattern, scrollingColors, true, 1.8, 16);
}

// Pattern Animation - Custom Scrolling Row
void customScrollingRowPattern() {
  currentPalette = gScrollingRowPalettes[ gCurrentPaletteNumber ];
  EVERY_N_SECONDS( 10 ) {
    gCurrentPaletteNumber = random(0, gScrollingRowPalettesCount);
  }
  customPattern(scrollingRowPattern, scrollingColors, false, 2.5, 16);
}

// Pattern Animation - Custom Scrolling Column
void customScrollingColumnPattern() {
  currentPalette = gScrollingColumnPalettes[ gCurrentPaletteNumber ];
  EVERY_N_SECONDS( 10 ) {
    gCurrentPaletteNumber = random(0, gScrollingColumnPalettesCount);
  }
  customPattern(scrollingColumnPattern, scrollingColors, false, 2.5, 16);
}

// Pattern Animation - Custom Crossing Lines
void customCrossLinesPattern() {
  currentPalette = gCrossLinesPalettes[ gCurrentPaletteNumber ];
  EVERY_N_SECONDS( 10 ) {
    gCurrentPaletteNumber = random(0, gCrossLinesPalettesCount);
  }
  customPattern(crossLinesPattern, scrollingColors, true, 3, 16);
}

// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX ANIMATION FUNCTIIONS END XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

// ---------------------------------------------------------------------------------------------------- customPattern () START  -----------------------------------

//Line Flipping for customPattern - Function for converting order of LEDs every other row
uint_least8_t FlipIndex(uint_least8_t nIndex, uint_least8_t nMidpoint)
{
  return nMidpoint * 2 - nIndex;
}

// Line Flipping Check for customPattern - Function for checking if current row needs to be converted or not (runs FlipIndex function)
uint_least8_t ConvertIndex(uint_least8_t i)
{
  if (15 <= i && i <= 28) {                                                  // Check if currently on 2nd line
    return FlipIndex(i, 21) + 1;
  }
  if (42 <= i && i <= 53) {                                                   // Check if currently on 4th line
    return FlipIndex(i, 47) + 1;
  }
    if (65 <= i && i <= 74) {                                                  // Check if currently on 6th line
      return FlipIndex(i, 69) + 1;
    }
  return i;                                                                 // if on 1st, 3rd or 5th, don't flip position
}

void customPattern(uint_least8_t pattern[NUM_LEDS], uint_least8_t patternColors[], bool reverse, float speed, uint_least8_t max) {
  // Function that creates the pattern animation using these variables:
  // pattern - the selected layout of the animation
  // patternColors - sequence of colors from palette to indexes
  // reverse - choose direction through true / false
  // speed - adjust the run speed of a loop, bigger number is slower
  // max - select the max number of colors from the color palette (jumps of 16 on gradient scale 0 - 255, total of 16 steps)

  currentBlending = LINEARBLEND;

  for (uint_least8_t x = 0; x < max; x++) {                                                                                     // Run through all Pattern Indexs, until you hit the MAX allowed index number
    potentialBrightness();                                                                                                      // Adjust brightness based on check
    for (uint_least8_t z = 0; z < (4 * speed); z++) {                                                                           // Speed adjustment
      myButton.update();
      myButtonIfCheck();
      for (uint_least8_t i = 0; i < NUM_LEDS; i++) {                                                                            // Run through all the LEDs, until you hit the last LED
        uint_least8_t convertedI = ConvertIndex(i);                                                                             // Run through line flipping function, flip if needed to swap LED position
        uint8_t color = (pattern[i] + x) % max;                                                                                 // Color is the index of the current LED, will be used in the next function to map to the color bridge patternColors[], so LEDs with the same index on the pattern get colored the same
        leds[convertedI] = ColorFromPalette(currentPalette, patternColors[color] * 16, 255, currentBlending);                   // color the LED using the currently selected pattern, with the selected gradient value based on (color), assuming gradient is in equal jumps of 16.
      }                                                                                                                         // i Loop end, run through all LEDs
      FastLED.delay(1);                                                                                                         // Delay by X milliseconds
    }                                                                                                                           // z Loop end, speed adjustment
  }                                                                                                                             // t Loop end, pattern indexes
}
