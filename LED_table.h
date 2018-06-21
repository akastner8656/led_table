/*
 * LED_table.h
 * 
 * @Authors: David Michael Plotnick, Andrew Kastner 
 * @Date: 22 April 2018
 * 
 * @Brief: Header file for HCC's LED table
 */

const int NUM_ROWS = 16; 
const int NUM_COLS = 10;

int rgbTable[NUM_ROWS][NUM_COLS];

// Possible color combinations
const int NONE       = 0;
const int BLUE       = 1;
const int GREEN      = 2;
const int BLUE_GREEN = 3;
const int RED        = 4;
const int RED_BLUE   = 5;
const int RED_GREEN  = 6;
const int RED_GREEN_BLUE = 7;


