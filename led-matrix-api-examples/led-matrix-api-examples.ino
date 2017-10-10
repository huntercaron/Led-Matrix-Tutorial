/*
 * Welcome to the RGB Matrix API Example Code
 * 
 * This Code will help you get up and running when using the LED matrix.
 * This sketch sets you up with some basic api calls
 * By Hunter Caron
 */
 
#include <Adafruit_GFX.h>   // Core graphics library
#include <RGBmatrixPanel.h> // Hardware-specific library

// Setting the Pins
#define CLK 8
#define OE  9
#define LAT 10
#define A   A0
#define B   A1
#define C   A2
#define D   A3

// Initializing Matrix
RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, false);

// Adding iterator value for Anim
int iterator = 0;

void setup() {
  // Starting the Matrix
  matrix.begin();

  // API Examples:


  // Basic Pixel Drawing
  
    // drawPixel(x,y, color);
  matrix.drawPixel(0, 0, matrix.Color333( 7,7,7 ));


  // Two Ways of Selecting Color:
  
    // matrix.Color333(0,0,0);
    // Red Green Blue
    // R/7 G/7 B/7
  matrix.drawPixel(0, 0, matrix.Color333( 0,7,4 ));
  
    // matrix.ColorHSV(0,0,0, true);
    // Hue Saturation Value
    // Hue/1500 Saturation/100 Value/100
  matrix.drawPixel(0, 1, matrix.ColorHSV( 800,100,100,true ));


  // Drawing Functions:
  
    // Draw Rectangle: border rectangle
    // drawRect(x, y, width, height, color);
  matrix.drawRect(2, 4, 5, 5, matrix.Color333(7,2,7));
    // Fill Rectangle: filled in rectangle
    // fillRect(x, y, width, height, color);
  matrix.fillRect(8, 4, 5, 5, matrix.Color333(2,5,7));
    // Fill Circle: filled in circle
    // fillRect(x, y, radius, color);
  matrix.fillCircle(19, 6, 3, matrix.Color333(0,5,2));

  // Type Functions:
  matrix.setCursor(4, 21);    // start at top middle, with one pixel of spacing
  matrix.setTextSize(1);     // size 1 == 8 pixels high
  matrix.setTextWrap(false); // Don't wrap at end of line - will do ourselves

  matrix.setTextColor(matrix.Color333(7,7,7));
  matrix.println("YSDN");

  // to clear the screen, write 0 over it
  // FillScreen(Color333(0,0,0)),

  // Thanks!
}

void loop() {
  // put your main code here, to run repeatedly:

  // Animate the rectangle from earlier
    // black coloured Line behind clears the LEDS
  matrix.drawLine(iterator-1, 14, iterator-1, 17, matrix.Color333(0,0,0));
    // Drawing the Rectangle
  matrix.fillRect(iterator, 14, 3, 3, matrix.Color333(2,5,7));

  if (iterator > 34) {
    iterator = -3;
  }
  iterator++;
  delay(10);
}
