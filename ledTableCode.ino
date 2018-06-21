#include "LED_table.h"
int rows = 0;
long randomValue;
unsigned long WaitStart;
long randomValueSelection;
void loopIsSuccessfulRandom();
void loopIsSuccessfulChecker();
void noSelection();

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));
}

void loop() 
{  
  int reLoopFunction = true;
  int valueEntered;
  WaitStart = millis();

  while(!Serial) 
  {
    if(millis() - WaitStart > 2000) break;
  }
  Serial.println("If you want to select a pattern, choose from this list:");
  delay(100);
  Serial.println("1: Randomly Generated Pattern");
  Serial.println("2: Moving Block Pattern");
  Serial.println("3: Square Pattern");
  Serial.println("4: Arrow Pattern");
  Serial.println("5: HCC Logo Pattern");
  delay(1000);
  Serial.println();
  Serial.println("Press a key from the list to view a pattern."); 
  
  while (reLoopFunction == true)
  {
    WaitStart = millis(); //If Serial.parseInt() is < 1 or > 3, come back to here. 
    while(!Serial.available()) 
    {
    if(millis() - WaitStart > 40000 && millis()- WaitStart < 40002 && valueEntered != 2 && valueEntered != 1 && valueEntered !=3 && valueEntered !=4){
    reLoopFunction = false;
    noSelection();
      }
    }
    while(Serial.available()) 
    {
    valueEntered = Serial.parseInt();
    }
    if (valueEntered < 1)
    {
      Serial.println("Invalid input.  Press an indicated key provided.");
    }
    else if (valueEntered > 5)
    {
      Serial.println("Invalid input.  Press an indicated key provided.");
    }
    else if (valueEntered == 1)
    {
      loopIsSuccessfulRandom();
    }
    else if (valueEntered == 2)
    {
      loopIsSuccessfulChecker();
    }
    else if (valueEntered == 3)
    {
      loopIsSuccessfulSquare();
    }
    else if (valueEntered == 4)
    {
      loopIsSuccessfulArrow();
    }
    else if (valueEntered == 5)
    {
      loopIsSuccessfulHcc();
    }
  }
}
void noSelection(){ //
Serial.println("No selection has been chosen.  Displaying random pattern.");
randomValueSelection = random(1);
switch (randomValueSelection)
  {
    case 0: randomMatrix(); break;
    case 1: checkerMatrix(); break;
  }
}
void loopIsSuccessfulRandom()
{
  Serial.println("You chose the Random Pattern.");
  Serial.println();
  randomMatrix();
}
void loopIsSuccessfulChecker()
{
  Serial.println("You chose the Checkered Pattern.");
  Serial.println();
  checkerMatrix();
}
void loopIsSuccessfulSquare()
{
  Serial.println("You chose the Square Pattern.");
  Serial.println();
  squareMatrix();
  
}
void loopIsSuccessfulArrow()
{
  Serial.println("You chose the Arrow Pattern.");
  Serial.println();
  arrowMatrix();
}
void loopIsSuccessfulHcc()
{
  Serial.println("You chose the HCC Pattern.");
  Serial.println();
  howardMatrix();
}

void randomMatrix()
  {
  int numRandomLoops;
  for (numRandomLoops = 0; numRandomLoops < 20; numRandomLoops++){
  for (rows; rows < NUM_ROWS; rows++) // row 1 goes to column 1 to 10, then row 2 goes to column 1 to 10
    { 
    for (int cols = 0; cols < NUM_COLS; cols++)
      {
    randomValue = random(7);
    switch (randomValue)
        {
      case 0: rgbTable[rows][cols] = BLUE; Serial.print(rgbTable[rows][cols]); break;
      case 1: rgbTable[rows][cols] = GREEN; Serial.print(rgbTable[rows][cols]); break;
      case 2: rgbTable[rows][cols] = BLUE_GREEN; Serial.print(rgbTable[rows][cols]); break;
      case 3: rgbTable[rows][cols] = RED; Serial.print(rgbTable[rows][cols]); break;
      case 4: rgbTable[rows][cols] = RED_BLUE; Serial.print(rgbTable[rows][cols]); break;
      case 5: rgbTable[rows][cols] = RED_GREEN; Serial.print(rgbTable[rows][cols]); break;
      case 6: rgbTable[rows][cols] = RED_GREEN_BLUE; Serial.print(rgbTable[rows][cols]); break;
        }
      }
      Serial.println();
    }
    delay(200);
    rows = 0;
    Serial.println();
  }
}

void checkerMatrix()
{
int x;
for (int numLoops = 0; numLoops < 4; numLoops++){
for (int x = 0; x < 2; x++){
for (rows; rows < NUM_ROWS; rows++)
  { 
  if (rows == (2-x) || rows == (3-x) || rows == (6-x) || rows == (7-x) || rows == (10-x) || rows == (11-x) || rows == (14-x) || rows == (15-x)) //section 1
    {
      for (int cols = 0; cols < NUM_COLS; cols++)
      {
        switch (cols)
        {
          case 0: rgbTable[rows][cols] = GREEN; Serial.print(rgbTable[rows][cols]); break; 
          case 1: rgbTable[rows][cols] = GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 2: rgbTable[rows][cols] = BLUE; Serial.print(rgbTable[rows][cols]); break; 
          case 3: rgbTable[rows][cols] = BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 4: rgbTable[rows][cols] = GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 5: rgbTable[rows][cols] = GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 6: rgbTable[rows][cols] = BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 7: rgbTable[rows][cols] = BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 8: rgbTable[rows][cols] = GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 9: rgbTable[rows][cols] = GREEN; Serial.print(rgbTable[rows][cols]); break;
        }
      }
      Serial.println();
    }
    if (rows == (0+15*x) || rows == (1-x) || rows == (4-x) || rows == (5-x) || rows == (8-x) || rows == (9-x) || rows == (12-x) || rows == (13-x)) //section 2
      {
      for (int cols = 0; cols < NUM_COLS; cols++)
        {
        switch (cols)
          {
          case 0: rgbTable[rows][cols] = BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 1: rgbTable[rows][cols] = BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 2: rgbTable[rows][cols] = GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 3: rgbTable[rows][cols] = GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 4: rgbTable[rows][cols] = BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 5: rgbTable[rows][cols] = BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 6: rgbTable[rows][cols] = GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 7: rgbTable[rows][cols] = GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 8: rgbTable[rows][cols] = BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 9: rgbTable[rows][cols] = BLUE; Serial.print(rgbTable[rows][cols]); break;
          }
        }
        Serial.println();
      }
    }
  delay(75);
  rows = 0;
  Serial.println();
  }
x = 0;
for (int x = 0; x < 2; x++){
for (rows; rows < NUM_ROWS; rows++)
  { 
  if (rows == (2+x) || rows == (3+x) || rows == (6+x) || rows == (7+x) || rows == (10+x) || rows == (11+x) || rows == (14+x) || rows == (15-15*x)) //section 1
    {
      for (int cols = 0; cols < NUM_COLS; cols++)
      {
        switch (cols)
        {
          case 0: rgbTable[rows][cols] = RED_BLUE; Serial.print(rgbTable[rows][cols]); break; 
          case 1: rgbTable[rows][cols] = RED_BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 2: rgbTable[rows][cols] = GREEN; Serial.print(rgbTable[rows][cols]); break; 
          case 3: rgbTable[rows][cols] = GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 4: rgbTable[rows][cols] = RED_BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 5: rgbTable[rows][cols] = RED_BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 6: rgbTable[rows][cols] = GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 7: rgbTable[rows][cols] = GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 8: rgbTable[rows][cols] = RED_BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 9: rgbTable[rows][cols] = RED_BLUE; Serial.print(rgbTable[rows][cols]); break;
        }
      }
      Serial.println();
    }
    if (rows == (0+x) || rows == (1+x) || rows == (4+x) || rows == (5+x) || rows == (8+x) || rows == (9+x) || rows == (12+x) || rows == (13+x)) //section 2
      {
      for (int cols = 0; cols < NUM_COLS; cols++)
        {
        switch (cols)
          {
          case 0: rgbTable[rows][cols] = GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 1: rgbTable[rows][cols] = GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 2: rgbTable[rows][cols] = RED_BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 3: rgbTable[rows][cols] = RED_BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 4: rgbTable[rows][cols] = GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 5: rgbTable[rows][cols] = GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 6: rgbTable[rows][cols] = RED_BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 7: rgbTable[rows][cols] = RED_BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 8: rgbTable[rows][cols] = GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 9: rgbTable[rows][cols] = GREEN; Serial.print(rgbTable[rows][cols]); break;
          }
        }
        Serial.println();
      }
    }
  delay(75);
  rows = 0;
  Serial.println();
  }
x = 0;
for (int x = 0; x < 2; x++){
for (rows; rows < NUM_ROWS; rows++)
  { 
  if (rows == (2-x) || rows == (3-x) || rows == (6-x) || rows == (7-x) || rows == (10-x) || rows == (11-x) || rows == (14-x) || rows == (15-x)) //section 1
    {
      for (int cols = 0; cols < NUM_COLS; cols++)
      {
        switch (cols)
        {
          case 0: rgbTable[rows][cols] = GREEN; Serial.print(rgbTable[rows][cols]); break; 
          case 1: rgbTable[rows][cols] = GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 2: rgbTable[rows][cols] = RED; Serial.print(rgbTable[rows][cols]); break; 
          case 3: rgbTable[rows][cols] = RED; Serial.print(rgbTable[rows][cols]); break;
          case 4: rgbTable[rows][cols] = GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 5: rgbTable[rows][cols] = GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 6: rgbTable[rows][cols] = RED; Serial.print(rgbTable[rows][cols]); break;
          case 7: rgbTable[rows][cols] = RED; Serial.print(rgbTable[rows][cols]); break;
          case 8: rgbTable[rows][cols] = GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 9: rgbTable[rows][cols] = GREEN; Serial.print(rgbTable[rows][cols]); break;
        }
      }
      Serial.println();
    }
    if (rows == (0+15*x) || rows == (1-x) || rows == (4-x) || rows == (5-x) || rows == (8-x) || rows == (9-x) || rows == (12-x) || rows == (13-x)) //section 2
      {
      for (int cols = 0; cols < NUM_COLS; cols++)
        {
        switch (cols)
          {
          case 0: rgbTable[rows][cols] = RED; Serial.print(rgbTable[rows][cols]); break;
          case 1: rgbTable[rows][cols] = RED; Serial.print(rgbTable[rows][cols]); break;
          case 2: rgbTable[rows][cols] = GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 3: rgbTable[rows][cols] = GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 4: rgbTable[rows][cols] = RED; Serial.print(rgbTable[rows][cols]); break;
          case 5: rgbTable[rows][cols] = RED; Serial.print(rgbTable[rows][cols]); break;
          case 6: rgbTable[rows][cols] = GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 7: rgbTable[rows][cols] = GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 8: rgbTable[rows][cols] = RED; Serial.print(rgbTable[rows][cols]); break;
          case 9: rgbTable[rows][cols] = RED; Serial.print(rgbTable[rows][cols]); break;
          }
        }
        Serial.println();
      }
    }
  delay(75);
  rows = 0;
  Serial.println();
  }
x = 0;
for (int x = 0; x < 2; x++){
for (rows; rows < NUM_ROWS; rows++)
  { 
  if (rows == (2+x) || rows == (3+x) || rows == (6+x) || rows == (7+x) || rows == (10+x) || rows == (11+x) || rows == (14+x) || rows == (15-15*x)) //section 1
    {
      for (int cols = 0; cols < NUM_COLS; cols++)
      {
        switch (cols)
        {
          case 0: rgbTable[rows][cols] = RED_BLUE; Serial.print(rgbTable[rows][cols]); break; 
          case 1: rgbTable[rows][cols] = RED_BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 2: rgbTable[rows][cols] = GREEN; Serial.print(rgbTable[rows][cols]); break; 
          case 3: rgbTable[rows][cols] = GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 4: rgbTable[rows][cols] = RED_BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 5: rgbTable[rows][cols] = RED_BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 6: rgbTable[rows][cols] = GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 7: rgbTable[rows][cols] = GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 8: rgbTable[rows][cols] = RED_BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 9: rgbTable[rows][cols] = RED_BLUE; Serial.print(rgbTable[rows][cols]); break;
        }
      }
      Serial.println();
    }
    if (rows == (0+x) || rows == (1+x) || rows == (4+x) || rows == (5+x) || rows == (8+x) || rows == (9+x) || rows == (12+x) || rows == (13+x)) //section 2
      {
      for (int cols = 0; cols < NUM_COLS; cols++)
        {
        switch (cols)
          {
          case 0: rgbTable[rows][cols] = GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 1: rgbTable[rows][cols] = GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 2: rgbTable[rows][cols] = RED_BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 3: rgbTable[rows][cols] = RED_BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 4: rgbTable[rows][cols] = GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 5: rgbTable[rows][cols] = GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 6: rgbTable[rows][cols] = RED_BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 7: rgbTable[rows][cols] = RED_BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 8: rgbTable[rows][cols] = GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 9: rgbTable[rows][cols] = GREEN; Serial.print(rgbTable[rows][cols]); break;
          }
        }
        Serial.println();
      }
    }
  delay(75);
  rows = 0;
  Serial.println();
  }
x = 0;
for (int x = 0; x < 2; x++){
for (rows; rows < NUM_ROWS; rows++)
  { 
  if (rows == (2-x) || rows == (3-x) || rows == (6-x) || rows == (7-x) || rows == (10-x) || rows == (11-x) || rows == (14-x) || rows == (15-x)) //section 1
    {
      for (int cols = 0; cols < NUM_COLS; cols++)
      {
        switch (cols)
        {
          case 0: rgbTable[rows][cols] = GREEN; Serial.print(rgbTable[rows][cols]); break; 
          case 1: rgbTable[rows][cols] = GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 2: rgbTable[rows][cols] = BLUE; Serial.print(rgbTable[rows][cols]); break; 
          case 3: rgbTable[rows][cols] = BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 4: rgbTable[rows][cols] = GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 5: rgbTable[rows][cols] = GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 6: rgbTable[rows][cols] = BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 7: rgbTable[rows][cols] = BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 8: rgbTable[rows][cols] = GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 9: rgbTable[rows][cols] = GREEN; Serial.print(rgbTable[rows][cols]); break;
        }
      }
      Serial.println();
    }
    if (rows == (0-15*x) || rows == (1-x) || rows == (4-x) || rows == (5-x) || rows == (8-x) || rows == (9-x) || rows == (12-x) || rows == (13-x)) //section 2
      {
      for (int cols = 0; cols < NUM_COLS; cols++)
        {
        switch (cols)
          {
          case 0: rgbTable[rows][cols] = BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 1: rgbTable[rows][cols] = BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 2: rgbTable[rows][cols] = GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 3: rgbTable[rows][cols] = GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 4: rgbTable[rows][cols] = BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 5: rgbTable[rows][cols] = BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 6: rgbTable[rows][cols] = GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 7: rgbTable[rows][cols] = GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 8: rgbTable[rows][cols] = BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 9: rgbTable[rows][cols] = BLUE; Serial.print(rgbTable[rows][cols]); break;
          }
        }
        Serial.println();
      }
    }
  delay(75);
  rows = 0;
  Serial.println();
  }
x = 0;
for (int x = 0; x < 2; x++){
for (rows; rows < NUM_ROWS; rows++)
  { 
  if (rows == (2+x) || rows == (3+x) || rows == (6+x) || rows == (7+x) || rows == (10+x) || rows == (11+x) || rows == (14+x) || rows == (15-15*x)) //section 1
    {
      for (int cols = 0; cols < NUM_COLS; cols++)
      {
        switch (cols)
        {
          case 0: rgbTable[rows][cols] = BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 1: rgbTable[rows][cols] = BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 2: rgbTable[rows][cols] = RED_GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 3: rgbTable[rows][cols] = RED_GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 4: rgbTable[rows][cols] = BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 5: rgbTable[rows][cols] = BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 6: rgbTable[rows][cols] = RED_GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 7: rgbTable[rows][cols] = RED_GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 8: rgbTable[rows][cols] = BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 9: rgbTable[rows][cols] = BLUE; Serial.print(rgbTable[rows][cols]); break;
        }
      }
      Serial.println();
    }
    if (rows == (0+x) || rows == (1+x) || rows == (4+x) || rows == (5+x) || rows == (8+x) || rows == (9+x) || rows == (12+x) || rows == (13+x)) //section 2
      {
      for (int cols = 0; cols < NUM_COLS; cols++)
        {
        switch (cols)
          {
          case 0: rgbTable[rows][cols] = RED_GREEN; Serial.print(rgbTable[rows][cols]); break; 
          case 1: rgbTable[rows][cols] = RED_GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 2: rgbTable[rows][cols] = BLUE; Serial.print(rgbTable[rows][cols]); break; 
          case 3: rgbTable[rows][cols] = BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 4: rgbTable[rows][cols] = RED_GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 5: rgbTable[rows][cols] = RED_GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 6: rgbTable[rows][cols] = BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 7: rgbTable[rows][cols] = BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 8: rgbTable[rows][cols] = RED_GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 9: rgbTable[rows][cols] = RED_GREEN; Serial.print(rgbTable[rows][cols]); break;
          }
        }
        Serial.println();
      }
    }
  delay(75);
  rows = 0;
  Serial.println();
  }
for (int x = 0; x < 2; x++){
for (rows; rows < NUM_ROWS; rows++)
  { 
  if (rows == (2-x) || rows == (3-x) || rows == (6-x) || rows == (7-x) || rows == (10-x) || rows == (11-x) || rows == (14-x) || rows == (15-x)) //section 1
    {
      for (int cols = 0; cols < NUM_COLS; cols++)
      {
        switch (cols)
        {
          case 0: rgbTable[rows][cols] = RED; Serial.print(rgbTable[rows][cols]); break; 
          case 1: rgbTable[rows][cols] = RED; Serial.print(rgbTable[rows][cols]); break;
          case 2: rgbTable[rows][cols] = BLUE; Serial.print(rgbTable[rows][cols]); break; 
          case 3: rgbTable[rows][cols] = BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 4: rgbTable[rows][cols] = RED; Serial.print(rgbTable[rows][cols]); break;
          case 5: rgbTable[rows][cols] = RED; Serial.print(rgbTable[rows][cols]); break;
          case 6: rgbTable[rows][cols] = BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 7: rgbTable[rows][cols] = BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 8: rgbTable[rows][cols] = RED; Serial.print(rgbTable[rows][cols]); break;
          case 9: rgbTable[rows][cols] = RED; Serial.print(rgbTable[rows][cols]); break;
        }
      }
      Serial.println();
    }
    if (rows == (0-15*x) || rows == (1-x) || rows == (4-x) || rows == (5-x) || rows == (8-x) || rows == (9-x) || rows == (12-x) || rows == (13-x)) //section 2
      {
      for (int cols = 0; cols < NUM_COLS; cols++)
        {
        switch (cols)
          {
          case 0: rgbTable[rows][cols] = BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 1: rgbTable[rows][cols] = BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 2: rgbTable[rows][cols] = RED; Serial.print(rgbTable[rows][cols]); break;
          case 3: rgbTable[rows][cols] = RED; Serial.print(rgbTable[rows][cols]); break;
          case 4: rgbTable[rows][cols] = BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 5: rgbTable[rows][cols] = BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 6: rgbTable[rows][cols] = RED; Serial.print(rgbTable[rows][cols]); break;
          case 7: rgbTable[rows][cols] = RED; Serial.print(rgbTable[rows][cols]); break;
          case 8: rgbTable[rows][cols] = BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 9: rgbTable[rows][cols] = BLUE; Serial.print(rgbTable[rows][cols]); break;
          }
        }
        Serial.println();
      }
    }
  delay(75);
  rows = 0;
  Serial.println();
  }
x = 0;
for (int x = 0; x < 2; x++){
for (rows; rows < NUM_ROWS; rows++)
  { 
  if (rows == (2+x) || rows == (3+x) || rows == (6+x) || rows == (7+x) || rows == (10+x) || rows == (11+x) || rows == (14+x) || rows == (15-15*x)) //section 1
    {
      for (int cols = 0; cols < NUM_COLS; cols++)
      {
        switch (cols)
        {
          case 0: rgbTable[rows][cols] = BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 1: rgbTable[rows][cols] = BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 2: rgbTable[rows][cols] = RED_GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 3: rgbTable[rows][cols] = RED_GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 4: rgbTable[rows][cols] = BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 5: rgbTable[rows][cols] = BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 6: rgbTable[rows][cols] = RED_GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 7: rgbTable[rows][cols] = RED_GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 8: rgbTable[rows][cols] = BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 9: rgbTable[rows][cols] = BLUE; Serial.print(rgbTable[rows][cols]); break;
        }
      }
      Serial.println();
    }
    if (rows == (0+x) || rows == (1+x) || rows == (4+x) || rows == (5+x) || rows == (8+x) || rows == (9+x) || rows == (12+x) || rows == (13+x)) //section 2
      {
      for (int cols = 0; cols < NUM_COLS; cols++)
        {
        switch (cols)
          {
          case 0: rgbTable[rows][cols] = RED_GREEN; Serial.print(rgbTable[rows][cols]); break; 
          case 1: rgbTable[rows][cols] = RED_GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 2: rgbTable[rows][cols] = BLUE; Serial.print(rgbTable[rows][cols]); break; 
          case 3: rgbTable[rows][cols] = BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 4: rgbTable[rows][cols] = RED_GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 5: rgbTable[rows][cols] = RED_GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 6: rgbTable[rows][cols] = BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 7: rgbTable[rows][cols] = BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 8: rgbTable[rows][cols] = RED_GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 9: rgbTable[rows][cols] = RED_GREEN; Serial.print(rgbTable[rows][cols]); break;
          }
        }
        Serial.println();
      }
    }
  delay(75);
  rows = 0;
  Serial.println();
  }
}
for (rows; rows < NUM_ROWS; rows++)
  { 
  if (rows == (2-x) || rows == (3-x) || rows == (6-x) || rows == (7-x) || rows == (10-x) || rows == (11-x) || rows == (14-x) || rows == (15-x)) //section 1
    {
      for (int cols = 0; cols < NUM_COLS; cols++)
      {
        switch (cols)
        {
          case 0: rgbTable[rows][cols] = GREEN; Serial.print(rgbTable[rows][cols]); break; 
          case 1: rgbTable[rows][cols] = GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 2: rgbTable[rows][cols] = BLUE; Serial.print(rgbTable[rows][cols]); break; 
          case 3: rgbTable[rows][cols] = BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 4: rgbTable[rows][cols] = GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 5: rgbTable[rows][cols] = GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 6: rgbTable[rows][cols] = BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 7: rgbTable[rows][cols] = BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 8: rgbTable[rows][cols] = GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 9: rgbTable[rows][cols] = GREEN; Serial.print(rgbTable[rows][cols]); break;
        }
      }
      Serial.println();
    }
    if (rows == (0+15*x) || rows == (1-x) || rows == (4-x) || rows == (5-x) || rows == (8-x) || rows == (9-x) || rows == (12-x) || rows == (13-x)) //section 2
    {
      for (int cols = 0; cols < NUM_COLS; cols++)
      {
        switch (cols)
        {
          case 0: rgbTable[rows][cols] = BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 1: rgbTable[rows][cols] = BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 2: rgbTable[rows][cols] = GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 3: rgbTable[rows][cols] = GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 4: rgbTable[rows][cols] = BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 5: rgbTable[rows][cols] = BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 6: rgbTable[rows][cols] = GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 7: rgbTable[rows][cols] = GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 8: rgbTable[rows][cols] = BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 9: rgbTable[rows][cols] = BLUE; Serial.print(rgbTable[rows][cols]); break;
        }
      }
        Serial.println();
    }
  }
}
void squareMatrix()
{
for (int numPatternLoops = 0; numPatternLoops < 6; numPatternLoops++){
for (rows; rows < NUM_ROWS; rows++){
  for (int cols = 0; cols < NUM_COLS; cols++){
    if (rows == 7 || rows == 8){
    switch (cols)
      {
      case 0: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 1: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 2: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 3: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 4: rgbTable[rows][cols] = RED;  Serial.print(rgbTable[rows][cols]); break;
      case 5: rgbTable[rows][cols] = RED;  Serial.print(rgbTable[rows][cols]); break;
      case 6: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 7: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 8: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 9: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      }
    }
    else switch (cols)
    {
      case 0: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 1: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 2: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 3: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 4: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 5: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 6: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 7: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 8: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 9: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
    }
  }
  Serial.println();
}
delay(500);
rows = 0;
Serial.println();
for (rows = 0; rows < NUM_ROWS; rows++){
  for (int cols = 0; cols < NUM_COLS; cols++){
    if (rows == 3 || rows == 4 || rows == 11 || rows == 12 ){
      switch (cols){
      case 0: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 1: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 2: rgbTable[rows][cols] = GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 3: rgbTable[rows][cols] = GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 4: rgbTable[rows][cols] = GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 5: rgbTable[rows][cols] = GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 6: rgbTable[rows][cols] = GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 7: rgbTable[rows][cols] = GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 8: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 9: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      }
    }
    else if (rows == 5 || rows == 6 || rows == 9 || rows == 10){
    switch (cols)
      {
      case 0: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 1: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 2: rgbTable[rows][cols] = GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 3: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 4: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 5: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 6: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 7: rgbTable[rows][cols] = GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 8: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 9: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      }
    }
    else if (rows == 7 || rows == 8){
      switch (cols)
      {
      case 0: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 1: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 2: rgbTable[rows][cols] = GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 3: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 4: rgbTable[rows][cols] = RED;  Serial.print(rgbTable[rows][cols]); break;
      case 5: rgbTable[rows][cols] = RED;  Serial.print(rgbTable[rows][cols]); break;
      case 6: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 7: rgbTable[rows][cols] = GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 8: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 9: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
        }
      }
    else if (rows == 0 || rows == 1 || rows == 2 || rows == 13 || rows == 14 || rows == 15){
      switch (cols)
      {
      case 0: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 1: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 2: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 3: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 4: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 5: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 6: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 7: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 8: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 9: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
        }
      }
    }
    Serial.println();
  }
delay(500);
rows = 0;
Serial.println();
for (rows = 0; rows < NUM_ROWS; rows++){
  for (int cols = 0; cols < NUM_COLS; cols++){
    if (rows == 0 || rows == 15){
      switch (cols){
      case 0: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      case 1: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      case 2: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      case 3: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      case 4: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      case 5: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      case 6: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      case 7: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      case 8: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      case 9: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      }
    }
    else if (rows == 1 || rows == 2 || rows == 13 || rows == 14){
      switch (cols){
      case 0: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      case 1: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 2: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 3: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 4: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 5: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 6: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 7: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 8: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 9: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      }
    }
    else if (rows == 3 || rows == 4 || rows == 11 || rows == 12){
      switch (cols){
      case 0: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      case 1: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 2: rgbTable[rows][cols] = GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 3: rgbTable[rows][cols] = GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 4: rgbTable[rows][cols] = GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 5: rgbTable[rows][cols] = GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 6: rgbTable[rows][cols] = GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 7: rgbTable[rows][cols] = GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 8: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 9: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      }
    }
    else if (rows == 5 || rows == 6 || rows == 9 || rows == 10){
      switch (cols){
      case 0: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      case 1: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 2: rgbTable[rows][cols] = GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 3: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 4: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 5: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 6: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 7: rgbTable[rows][cols] = GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 8: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 9: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      }
    }
    else if (rows == 7 || rows == 8){
      switch (cols){
      case 0: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      case 1: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 2: rgbTable[rows][cols] = GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 3: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 4: rgbTable[rows][cols] = RED;  Serial.print(rgbTable[rows][cols]); break;
      case 5: rgbTable[rows][cols] = RED;  Serial.print(rgbTable[rows][cols]); break;
      case 6: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 7: rgbTable[rows][cols] = GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 8: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 9: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      }
    }
  }
    Serial.println();
  }
delay(500);
rows = 0;
Serial.println();
for (rows = 0; rows < NUM_ROWS; rows++){
  for (int cols = 0; cols < NUM_COLS; cols++){
    if (rows == 0 || rows == 15){
      switch (cols){
      case 0: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      case 1: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      case 2: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      case 3: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      case 4: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      case 5: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      case 6: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      case 7: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      case 8: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      case 9: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      }
    }
    else if (rows == 1 || rows == 2 || rows == 13 || rows == 14){
      switch (cols){
      case 0: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      case 1: rgbTable[rows][cols] = BLUE_GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 2: rgbTable[rows][cols] = BLUE_GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 3: rgbTable[rows][cols] = BLUE_GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 4: rgbTable[rows][cols] = BLUE_GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 5: rgbTable[rows][cols] = BLUE_GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 6: rgbTable[rows][cols] = BLUE_GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 7: rgbTable[rows][cols] = BLUE_GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 8: rgbTable[rows][cols] = BLUE_GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 9: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      }
    }
    else if (rows == 3 || rows == 4 || rows == 11 || rows == 12){
      switch (cols){
      case 0: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      case 1: rgbTable[rows][cols] = BLUE_GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 2: rgbTable[rows][cols] = GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 3: rgbTable[rows][cols] = GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 4: rgbTable[rows][cols] = GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 5: rgbTable[rows][cols] = GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 6: rgbTable[rows][cols] = GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 7: rgbTable[rows][cols] = GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 8: rgbTable[rows][cols] = BLUE_GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 9: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      }
    }
    else if (rows == 5 || rows == 6 || rows == 9 || rows == 10){
      switch (cols){
      case 0: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      case 1: rgbTable[rows][cols] = BLUE_GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 2: rgbTable[rows][cols] = GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 3: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 4: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 5: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 6: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 7: rgbTable[rows][cols] = GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 8: rgbTable[rows][cols] = BLUE_GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 9: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      }
    }
    else if (rows == 7 || rows == 8){
      switch (cols){
      case 0: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      case 1: rgbTable[rows][cols] = BLUE_GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 2: rgbTable[rows][cols] = GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 3: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 4: rgbTable[rows][cols] = RED;  Serial.print(rgbTable[rows][cols]); break;
      case 5: rgbTable[rows][cols] = RED;  Serial.print(rgbTable[rows][cols]); break;
      case 6: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 7: rgbTable[rows][cols] = GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 8: rgbTable[rows][cols] = BLUE_GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 9: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      }
    }
  }
    Serial.println();
  }
delay(500);
rows = 0;
Serial.println();
for (rows = 0; rows < NUM_ROWS; rows++){
  for (int cols = 0; cols < NUM_COLS; cols++){
    if (rows == 0 || rows == 15){
      switch (cols){
      case 0: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      case 1: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      case 2: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      case 3: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      case 4: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      case 5: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      case 6: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      case 7: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      case 8: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      case 9: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      }
    }
    else if (rows == 1 || rows == 2 || rows == 13 || rows == 14){
      switch (cols){
      case 0: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      case 1: rgbTable[rows][cols] = BLUE_GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 2: rgbTable[rows][cols] = BLUE_GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 3: rgbTable[rows][cols] = BLUE_GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 4: rgbTable[rows][cols] = BLUE_GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 5: rgbTable[rows][cols] = BLUE_GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 6: rgbTable[rows][cols] = BLUE_GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 7: rgbTable[rows][cols] = BLUE_GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 8: rgbTable[rows][cols] = BLUE_GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 9: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      }
    }
    else if (rows == 3 || rows == 4 || rows == 11 || rows == 12){
      switch (cols){
      case 0: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      case 1: rgbTable[rows][cols] = BLUE_GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 2: rgbTable[rows][cols] = GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 3: rgbTable[rows][cols] = GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 4: rgbTable[rows][cols] = GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 5: rgbTable[rows][cols] = GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 6: rgbTable[rows][cols] = GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 7: rgbTable[rows][cols] = GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 8: rgbTable[rows][cols] = BLUE_GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 9: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      }
    }
    else if (rows == 5 || rows == 6 || rows == 9 || rows == 10){
      switch (cols){
      case 0: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      case 1: rgbTable[rows][cols] = BLUE_GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 2: rgbTable[rows][cols] = GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 3: rgbTable[rows][cols] = RED_GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 4: rgbTable[rows][cols] = RED_GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 5: rgbTable[rows][cols] = RED_GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 6: rgbTable[rows][cols] = RED_GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 7: rgbTable[rows][cols] = GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 8: rgbTable[rows][cols] = BLUE_GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 9: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      }
    }
    else if (rows == 7 || rows == 8){
      switch (cols){
      case 0: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      case 1: rgbTable[rows][cols] = BLUE_GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 2: rgbTable[rows][cols] = GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 3: rgbTable[rows][cols] = RED_GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 4: rgbTable[rows][cols] = RED;  Serial.print(rgbTable[rows][cols]); break;
      case 5: rgbTable[rows][cols] = RED;  Serial.print(rgbTable[rows][cols]); break;
      case 6: rgbTable[rows][cols] = RED_GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 7: rgbTable[rows][cols] = GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 8: rgbTable[rows][cols] = BLUE_GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 9: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      }
    }
  }
    Serial.println();
}
delay(500);
rows = 0;
Serial.println();
for (rows = 0; rows < NUM_ROWS; rows++){
  for (int cols = 0; cols < NUM_COLS; cols++){
    if (rows == 0 || rows == 15){
      switch (cols){
      case 0: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      case 1: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      case 2: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      case 3: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      case 4: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      case 5: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      case 6: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      case 7: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      case 8: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      case 9: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      }
    }
    else if (rows == 1 || rows == 2 || rows == 13 || rows == 14){
      switch (cols){
      case 0: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      case 1: rgbTable[rows][cols] = BLUE_GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 2: rgbTable[rows][cols] = BLUE_GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 3: rgbTable[rows][cols] = BLUE_GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 4: rgbTable[rows][cols] = BLUE_GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 5: rgbTable[rows][cols] = BLUE_GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 6: rgbTable[rows][cols] = BLUE_GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 7: rgbTable[rows][cols] = BLUE_GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 8: rgbTable[rows][cols] = BLUE_GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 9: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      }
    }
    else if (rows == 3 || rows == 4 || rows == 11 || rows == 12){
      switch (cols){
      case 0: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      case 1: rgbTable[rows][cols] = BLUE_GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 2: rgbTable[rows][cols] = GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 3: rgbTable[rows][cols] = GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 4: rgbTable[rows][cols] = GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 5: rgbTable[rows][cols] = GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 6: rgbTable[rows][cols] = GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 7: rgbTable[rows][cols] = GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 8: rgbTable[rows][cols] = BLUE_GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 9: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      }
    }
    else if (rows == 5 || rows == 6 || rows == 9 || rows == 10){
      switch (cols){
      case 0: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      case 1: rgbTable[rows][cols] = BLUE_GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 2: rgbTable[rows][cols] = GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 3: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 4: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 5: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 6: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 7: rgbTable[rows][cols] = GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 8: rgbTable[rows][cols] = BLUE_GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 9: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      }
    }
    else if (rows == 7 || rows == 8){
      switch (cols){
      case 0: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      case 1: rgbTable[rows][cols] = BLUE_GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 2: rgbTable[rows][cols] = GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 3: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 4: rgbTable[rows][cols] = RED;  Serial.print(rgbTable[rows][cols]); break;
      case 5: rgbTable[rows][cols] = RED;  Serial.print(rgbTable[rows][cols]); break;
      case 6: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 7: rgbTable[rows][cols] = GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 8: rgbTable[rows][cols] = BLUE_GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 9: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      }
    }
  }
    Serial.println();
  }
delay(500);
rows = 0;
Serial.println();
for (rows = 0; rows < NUM_ROWS; rows++){
  for (int cols = 0; cols < NUM_COLS; cols++){
    if (rows == 0 || rows == 15){
      switch (cols){
      case 0: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      case 1: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      case 2: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      case 3: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      case 4: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      case 5: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      case 6: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      case 7: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      case 8: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      case 9: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      }
    }
    else if (rows == 1 || rows == 2 || rows == 13 || rows == 14){
      switch (cols){
      case 0: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      case 1: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 2: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 3: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 4: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 5: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 6: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 7: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 8: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 9: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      }
    }
    else if (rows == 3 || rows == 4 || rows == 11 || rows == 12){
      switch (cols){
      case 0: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      case 1: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 2: rgbTable[rows][cols] = GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 3: rgbTable[rows][cols] = GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 4: rgbTable[rows][cols] = GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 5: rgbTable[rows][cols] = GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 6: rgbTable[rows][cols] = GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 7: rgbTable[rows][cols] = GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 8: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 9: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      }
    }
    else if (rows == 5 || rows == 6 || rows == 9 || rows == 10){
      switch (cols){
      case 0: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      case 1: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 2: rgbTable[rows][cols] = GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 3: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 4: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 5: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 6: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 7: rgbTable[rows][cols] = GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 8: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 9: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      }
    }
    else if (rows == 7 || rows == 8){
      switch (cols){
      case 0: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      case 1: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 2: rgbTable[rows][cols] = GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 3: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 4: rgbTable[rows][cols] = RED;  Serial.print(rgbTable[rows][cols]); break;
      case 5: rgbTable[rows][cols] = RED;  Serial.print(rgbTable[rows][cols]); break;
      case 6: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 7: rgbTable[rows][cols] = GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 8: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 9: rgbTable[rows][cols] = BLUE;  Serial.print(rgbTable[rows][cols]); break;
      }
    }
  }
    Serial.println();
  }
delay(500);
rows = 0;
Serial.println();
for (rows = 0; rows < NUM_ROWS; rows++){
  for (int cols = 0; cols < NUM_COLS; cols++){
    if (rows == 3 || rows == 4 || rows == 11 || rows == 12 ){
      switch (cols){
      case 0: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 1: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 2: rgbTable[rows][cols] = GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 3: rgbTable[rows][cols] = GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 4: rgbTable[rows][cols] = GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 5: rgbTable[rows][cols] = GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 6: rgbTable[rows][cols] = GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 7: rgbTable[rows][cols] = GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 8: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 9: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      }
    }
    else if (rows == 5 || rows == 6 || rows == 9 || rows == 10){
    switch (cols)
      {
      case 0: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 1: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 2: rgbTable[rows][cols] = GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 3: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 4: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 5: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 6: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 7: rgbTable[rows][cols] = GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 8: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 9: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      }
    }
    else if (rows == 7 || rows == 8){
      switch (cols)
      {
      case 0: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 1: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 2: rgbTable[rows][cols] = GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 3: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 4: rgbTable[rows][cols] = RED;  Serial.print(rgbTable[rows][cols]); break;
      case 5: rgbTable[rows][cols] = RED;  Serial.print(rgbTable[rows][cols]); break;
      case 6: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 7: rgbTable[rows][cols] = GREEN;  Serial.print(rgbTable[rows][cols]); break;
      case 8: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 9: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
        }
      }
    else if (rows == 0 || rows == 1 || rows == 2 || rows == 13 || rows == 14 || rows == 15){
      switch (cols)
      {
      case 0: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 1: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 2: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 3: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 4: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 5: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 6: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 7: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 8: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 9: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
        }
      }
    }
    Serial.println();
  }
delay(500);
rows = 0;
Serial.println();
for (rows; rows < NUM_ROWS; rows++){
  for (int cols = 0; cols < NUM_COLS; cols++){
    if (rows == 7 || rows == 8){
    switch (cols)
      {
      case 0: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 1: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 2: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 3: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 4: rgbTable[rows][cols] = RED;  Serial.print(rgbTable[rows][cols]); break;
      case 5: rgbTable[rows][cols] = RED;  Serial.print(rgbTable[rows][cols]); break;
      case 6: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 7: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 8: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 9: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      }
    }
    else switch (cols)
    {
      case 0: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 1: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 2: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 3: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 4: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 5: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 6: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 7: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 8: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 9: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
    }
  }
  Serial.println();
}
delay(500);
rows = 0;
Serial.println();
for (rows; rows < NUM_ROWS; rows++){
  for (int cols = 0; cols < NUM_COLS; cols++){
    switch(cols)
    {
      case 0: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 1: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 2: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 3: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 4: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 5: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 6: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 7: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 8: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      case 9: rgbTable[rows][cols] = NONE;  Serial.print(rgbTable[rows][cols]); break;
      }
    }
  Serial.println();
  }
delay(500);
rows = 0;
Serial.println();
}
}
void arrowMatrix()
{
int x;
for (int numPatternLoops = 1; numPatternLoops < 6; numPatternLoops++){
for (x = 0; x < 10; x++){
  for (rows; rows < NUM_ROWS; rows++)
  { 
    for (int cols = 0; cols < NUM_COLS; cols++)
    {
      if (rows == 0 || rows == 6 || rows == 7 || rows == 8 || rows == 9 || rows == 15)
      {
        switch (cols) //This code will never change, regardless of the input.
        {
          case 0: rgbTable[rows][cols] = RED_GREEN_BLUE; Serial.print(rgbTable[rows][cols]); break; 
          case 1: rgbTable[rows][cols] = RED_GREEN_BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 2: rgbTable[rows][cols] = RED_GREEN_BLUE; Serial.print(rgbTable[rows][cols]); break; 
          case 3: rgbTable[rows][cols] = RED_GREEN_BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 4: rgbTable[rows][cols] = RED_GREEN_BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 5: rgbTable[rows][cols] = RED_GREEN_BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 6: rgbTable[rows][cols] = RED_GREEN_BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 7: rgbTable[rows][cols] = RED_GREEN_BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 8: rgbTable[rows][cols] = RED_GREEN_BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 9: rgbTable[rows][cols] = RED_GREEN_BLUE; Serial.print(rgbTable[rows][cols]); break;
          }
        }
        else if (rows == 1 || rows == 5 || rows == 10 || rows == 14)
        {
          switch (10+cols-x)
          {
          case 1: rgbTable[rows][cols] = RED_GREEN_BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 2: rgbTable[rows][cols] = RED_GREEN_BLUE; Serial.print(rgbTable[rows][cols]); break; 
          case 3: rgbTable[rows][cols] = RED_GREEN_BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 4: rgbTable[rows][cols] = RED_GREEN_BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 5: rgbTable[rows][cols] = RED_GREEN_BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 6: rgbTable[rows][cols] = RED; Serial.print(rgbTable[rows][cols]); break;
          case 7: rgbTable[rows][cols] = RED_GREEN_BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 8: rgbTable[rows][cols] = RED_GREEN_BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 9: rgbTable[rows][cols] = RED_GREEN_BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 10: rgbTable[rows][cols] = RED_GREEN_BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 11: rgbTable[rows][cols] = RED_GREEN_BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 12: rgbTable[rows][cols] = RED_GREEN_BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 13: rgbTable[rows][cols] = RED_GREEN_BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 14: rgbTable[rows][cols] = RED_GREEN_BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 15: rgbTable[rows][cols] = RED_GREEN_BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 16: rgbTable[rows][cols] = RED; Serial.print(rgbTable[rows][cols]); break;
          case 17: rgbTable[rows][cols] = RED_GREEN_BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 18: rgbTable[rows][cols] = RED_GREEN_BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 19: rgbTable[rows][cols] = RED_GREEN_BLUE; Serial.print(rgbTable[rows][cols]); break;
        }
      }
      else if (rows == 2 || rows == 4 || rows == 11 || rows == 13)
      {
        switch (10+cols-x)
        {
          case 1: rgbTable[rows][cols] = RED_GREEN_BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 2: rgbTable[rows][cols] = RED_GREEN_BLUE; Serial.print(rgbTable[rows][cols]); break; 
          case 3: rgbTable[rows][cols] = RED_GREEN_BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 4: rgbTable[rows][cols] = RED_GREEN_BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 5: rgbTable[rows][cols] = RED_GREEN_BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 6: rgbTable[rows][cols] = RED; Serial.print(rgbTable[rows][cols]); break;
          case 7: rgbTable[rows][cols] = RED; Serial.print(rgbTable[rows][cols]); break;
          case 8: rgbTable[rows][cols] = RED_GREEN_BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 9: rgbTable[rows][cols] = RED_GREEN_BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 10: rgbTable[rows][cols] = RED_GREEN_BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 11: rgbTable[rows][cols] = RED_GREEN_BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 12: rgbTable[rows][cols] = RED_GREEN_BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 13: rgbTable[rows][cols] = RED_GREEN_BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 14: rgbTable[rows][cols] = RED_GREEN_BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 15: rgbTable[rows][cols] = RED_GREEN_BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 16: rgbTable[rows][cols] = RED; Serial.print(rgbTable[rows][cols]); break;
          case 17: rgbTable[rows][cols] = RED; Serial.print(rgbTable[rows][cols]); break;
          case 18: rgbTable[rows][cols] = RED_GREEN_BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 19: rgbTable[rows][cols] = RED_GREEN_BLUE; Serial.print(rgbTable[rows][cols]); break;
        }
      }
      else if (rows == 3 || rows == 12)
      {
        switch (10+cols-x)
        {
          case 1: rgbTable[rows][cols] = RED; Serial.print(rgbTable[rows][cols]); break;
          case 2: rgbTable[rows][cols] = RED; Serial.print(rgbTable[rows][cols]); break; 
          case 3: rgbTable[rows][cols] = RED; Serial.print(rgbTable[rows][cols]); break;
          case 4: rgbTable[rows][cols] = RED; Serial.print(rgbTable[rows][cols]); break;
          case 5: rgbTable[rows][cols] = RED; Serial.print(rgbTable[rows][cols]); break;
          case 6: rgbTable[rows][cols] = RED; Serial.print(rgbTable[rows][cols]); break;
          case 7: rgbTable[rows][cols] = RED; Serial.print(rgbTable[rows][cols]); break;
          case 8: rgbTable[rows][cols] = RED; Serial.print(rgbTable[rows][cols]); break;
          case 9: rgbTable[rows][cols] = RED_GREEN_BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 10: rgbTable[rows][cols] = RED_GREEN_BLUE; Serial.print(rgbTable[rows][cols]); break; 
          case 11: rgbTable[rows][cols] = RED; Serial.print(rgbTable[rows][cols]); break;
          case 12: rgbTable[rows][cols] = RED; Serial.print(rgbTable[rows][cols]); break;
          case 13: rgbTable[rows][cols] = RED; Serial.print(rgbTable[rows][cols]); break;
          case 14: rgbTable[rows][cols] = RED; Serial.print(rgbTable[rows][cols]); break;
          case 15: rgbTable[rows][cols] = RED; Serial.print(rgbTable[rows][cols]); break;
          case 16: rgbTable[rows][cols] = RED; Serial.print(rgbTable[rows][cols]); break;
          case 17: rgbTable[rows][cols] = RED; Serial.print(rgbTable[rows][cols]); break;
          case 18: rgbTable[rows][cols] = RED; Serial.print(rgbTable[rows][cols]); break;
          case 19: rgbTable[rows][cols] = RED_GREEN_BLUE; Serial.print(rgbTable[rows][cols]); break;
        }
      }
    }
    Serial.println();
  }
  delay(100);
  rows = 0;
  Serial.println();
  }
}
}
void howardMatrix(){
  for (int numHowardLogoLoops = 0; numHowardLogoLoops < 4; numHowardLogoLoops++)
  {
  int x = 0;
  for (x; x <= 20; x++)
  {
  for (rows; rows < NUM_ROWS; rows++)
  {
    for (int cols = 0; cols < NUM_COLS; cols++)
    {
      if (rows == 1 || rows == 6 || rows == 10 || rows == 14)
      {
        switch (cols+x)
        {
          case 0: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 1: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 2: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 3: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 4: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 5: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 6: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 7: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 8: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 9: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 10: rgbTable[rows][cols] = RED_GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 11: rgbTable[rows][cols] = BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 12: rgbTable[rows][cols] = RED_GREEN; Serial.print(rgbTable[rows][cols]); break; 
          case 13: rgbTable[rows][cols] = RED_GREEN; Serial.print(rgbTable[rows][cols]); break; 
          case 14: rgbTable[rows][cols] = RED_GREEN; Serial.print(rgbTable[rows][cols]); break; 
          case 15: rgbTable[rows][cols] = RED_GREEN; Serial.print(rgbTable[rows][cols]); break; 
          case 16: rgbTable[rows][cols] = RED_GREEN; Serial.print(rgbTable[rows][cols]); break; 
          case 17: rgbTable[rows][cols] = RED_GREEN; Serial.print(rgbTable[rows][cols]); break; 
          case 18: rgbTable[rows][cols] = RED_GREEN; Serial.print(rgbTable[rows][cols]); break; 
          case 19: rgbTable[rows][cols] = BLUE; Serial.print(rgbTable[rows][cols]); break; 
          case 20: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 21: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 22: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 23: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 24: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 25: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 26: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 27: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 28: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 29: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
        }
      }
      if (rows == 0 || rows == 15)
      {
        switch (cols+x)
        {
          case 0: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 1: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 2: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 3: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 4: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 5: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 6: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 7: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 8: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 9: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 10: rgbTable[rows][cols] = RED_GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 11: rgbTable[rows][cols] = RED_GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 12: rgbTable[rows][cols] = RED_GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 13: rgbTable[rows][cols] = BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 14: rgbTable[rows][cols] = BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 15: rgbTable[rows][cols] = BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 16: rgbTable[rows][cols] = BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 17: rgbTable[rows][cols] = BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 18: rgbTable[rows][cols] = RED_GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 19: rgbTable[rows][cols] = RED_GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 20: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 21: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 22: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 23: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 24: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 25: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 26: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 27: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 28: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 29: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
        }
      }
      if (rows == 2 || rows == 5 || rows == 7 || rows == 11)
      {
        switch (cols+x)
        {
          case 0: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 1: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 2: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 3: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 4: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 5: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 6: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 7: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 8: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 9: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 10: rgbTable[rows][cols] = RED_GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 11: rgbTable[rows][cols] = BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 12: rgbTable[rows][cols] = RED_GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 13: rgbTable[rows][cols] = RED; Serial.print(rgbTable[rows][cols]); break;
          case 14: rgbTable[rows][cols] = RED; Serial.print(rgbTable[rows][cols]); break;
          case 15: rgbTable[rows][cols] = RED; Serial.print(rgbTable[rows][cols]); break;
          case 16: rgbTable[rows][cols] = RED; Serial.print(rgbTable[rows][cols]); break;
          case 17: rgbTable[rows][cols] = RED; Serial.print(rgbTable[rows][cols]); break;
          case 18: rgbTable[rows][cols] = RED_GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 19: rgbTable[rows][cols] = BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 20: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 21: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 22: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 23: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 24: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 25: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 26: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 27: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 28: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 29: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
        }
      }
      if (rows == 3 || rows == 4)
      {
        switch (cols+x)
        {
          case 0: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 1: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 2: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 3: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 4: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 5: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 6: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 7: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 8: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 9: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 10: rgbTable[rows][cols] = RED_GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 11: rgbTable[rows][cols] = BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 12: rgbTable[rows][cols] = RED_GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 13: rgbTable[rows][cols] = RED_GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 14: rgbTable[rows][cols] = RED_GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 15: rgbTable[rows][cols] = RED; Serial.print(rgbTable[rows][cols]); break;
          case 16: rgbTable[rows][cols] = RED_GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 17: rgbTable[rows][cols] = RED_GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 18: rgbTable[rows][cols] = RED_GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 19: rgbTable[rows][cols] = BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 20: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 21: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 22: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 23: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 24: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 25: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 26: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 27: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 28: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 29: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
        }
      }
      if (rows  == 8 || rows == 9 || rows == 12 || rows == 13)
      {
        switch (cols+x)
        {
          case 0: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 1: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 2: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 3: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 4: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 5: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 6: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 7: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 8: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 9: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 10: rgbTable[rows][cols] = RED_GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 11: rgbTable[rows][cols] = BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 12: rgbTable[rows][cols] = RED_GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 13: rgbTable[rows][cols] = RED; Serial.print(rgbTable[rows][cols]); break;
          case 14: rgbTable[rows][cols] = RED_GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 15: rgbTable[rows][cols] = RED_GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 16: rgbTable[rows][cols] = RED_GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 17: rgbTable[rows][cols] = RED; Serial.print(rgbTable[rows][cols]); break;
          case 18: rgbTable[rows][cols] = RED_GREEN; Serial.print(rgbTable[rows][cols]); break;
          case 19: rgbTable[rows][cols] = BLUE; Serial.print(rgbTable[rows][cols]); break;
          case 20: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 21: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 22: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 23: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 24: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 25: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 26: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 27: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 28: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
          case 29: rgbTable[rows][cols] = NONE; Serial.print(rgbTable[rows][cols]); break;
        }
      }
    }
    Serial.println();
  }
  if (x == 10)
  {
    delay (3000);
  }
  else delay (100);
  Serial.println();
  rows = 0;
  }
 }
}

