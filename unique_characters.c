// The MIT License (MIT)
//
// Copyright (c) 2017 Trevor Bakker
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#include <string.h>
#include <stdio.h>

// Purpose: Given a string, determine if all of its characters are unique
//          Let's assume it's ASCII so that's 128 characters 
//          Part 2: Do it without a data structure. Assume all lowercase 
//          because I want to fit it into 32 bits because bit shifting is fun
//          A 64 bit int could be used, so go and make that change for fun

#define NUM_ASCII 128

int allUnique( char * str )
{
  unsigned int characters[NUM_ASCII];

  char * ptr = str;

  memset( characters, 0, sizeof(NUM_ASCII)*128 );

  while( *str )
  {
    if( characters[*str] ) return 0;
    characters[*str++] = 1; 
  }
  return 1;
}

int allUniqueNoDataStructure( char * str )
{
  int characters;
  
  while( *str )
  {
    int bit  = *str++ - 'a';
    int mask = 1 << bit;

    if( characters & mask ) return 0;

    characters |= mask;
  }

  return 1;
}

int main()
{
  printf("Comparison using a data structure\n");
  printf("All unique in %s? %d\n", "foo", allUnique("foo") );
  printf("All unique in %s? %d\n", "fOo", allUnique("fOo") );
  printf("All unique in %s? %d\n", "123456asdfgASDF", allUnique("123456asdfgASDF") );
  printf("All unique in %s? %d\n", "1234", allUnique("1234") );
  printf("All unique in %s? %d\n", " .,~", allUnique(" .,~") );
  printf("All unique in %s? %d\n", "~.,~", allUnique("~.,~") );

  printf("\nNo data structure comparison\n");
  printf("All unique in %s? %d\n", "foo", allUniqueNoDataStructure("foo") );
  printf("All unique in %s? %d\n", "bar", allUniqueNoDataStructure("bar") );
  printf("All unique in %s? %d\n", "abcdefghijklmnopqrstuvwxyz", 
          allUniqueNoDataStructure("abcdefghijklmnopqrstuvwxyz") );
}
