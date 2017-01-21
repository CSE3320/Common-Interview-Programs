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

#include <stdio.h>

// Purpose: A recursive and iterative fibonacci sequence.  The sequence starts at 1 
//          as it was classically defined. To start it at 0, change the first number 
//          in each to 0

int fibonacci_recursive( int number )
{
  if( number == 1 || number == 2 ) return 1;
  return fibonacci_recursive( number - 1 ) + fibonacci_recursive( number - 2 );
}

int fibonacci_iterative( int number )
{
  int n_value = 1;
  int n_minus_one_value = 1;
  int value = 0;
  int i;

  value = 1; 

  for( i = 3; i < number + 1; i++ )
  {
    value             = n_value + n_minus_one_value; 
    n_minus_one_value = n_value;
    n_value           = value;
  }

  return value;
}

int main ()
{
  int i;

  printf("Calculating the first 10 numbers in the fibonacci sequence recursively\n");

  for( i = 1; i < 11; i++ )
  {
    printf("Index: %d in the fibonacci sequence is %d\n", i, fibonacci_recursive( i ) );
  }

  printf("\nCalculating the first 10 numbers in the fibonacci sequence iteratively\n");
  for( i = 1; i < 11; i++ )
  {
    printf("Index: %d in the fibonacci sequence is %d\n", i, fibonacci_iterative( i ) );
  }

  return 0;
}
