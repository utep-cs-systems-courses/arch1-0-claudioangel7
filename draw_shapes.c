#include <stdio.h>
#include "draw.h"


void print_arrow(char a)
{

  a-=0x20;
  for(char row = 0; row <11; row++){
    unsigned short rowBits = font_11x16[a][row];
    
    for(char col=0; col<16; col++){
      unsigned short colMask = 1 << (15-col);
      putchar((rowBits & colMask) ? '*' : ' ');
    }
    
    putchar('\n');

  }
}


/* Prints a size x size square whose left col is at startCol */
void print_square(int leftCol, int size)
{
  int i, j;
  int endCol = leftCol + size;
  for (int row = 0; row < size; row++){
    int col;
    for (col = 0; col < leftCol; col++) putchar(' ');
    for (       ; col < endCol;  col++) putchar('*');
    putchar('\n');
  }
}

// Prints a triangle of specified height whose left edge is at col leftCol.
void print_triangle(int leftCol, int size)
{
  for (int row = 0; row <= size; row++) {
    int minCol = leftCol + size - row, maxCol = leftCol + size + row;
    int col;
    for (col = 0; col < minCol; col++) putchar(' ');
    for (       ; col <= maxCol; col++) putchar('*');
    putchar('\n');
  }
}

