/*
 * Welcome to the RGB Matrix Boilerplate Code.
 * This Code will help you get up and running when using the LED matrix.
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


void setup() {
  // Starting the Matrix
  matrix.begin();

  // Rectangle to Start
  matrix.drawRect(16-3, 16-3, 6, 6, matrix.Color333(0,4,7));
}

void loop() {
  // put your main code here, to run repeatedly:
  
}
