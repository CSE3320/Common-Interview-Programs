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
#include <string.h>
#include <stdlib.h>


void swap( char* str, int left, int right ) 
{
  char tmp   = str[left];
  str[left]  = str[right];
  str[right] = tmp;
}

void permute( char * str, int i, int length )
{
  if( i == length )
  {
    printf("%s\n", str );
  }

  int j;

  for( j = i; j < length; j++ )
  {
    swap   ( str, i, j );
    permute( str, i + 1, length );
    swap   ( str, i, j );
  }
}

int main()
{
  char * str = ( char * ) malloc ( strlen( "ABCD" ) );
  memcpy( str, "ABCD", strlen("ABCD") );

  permute( str, 0, ( int ) strlen( str ) );

  free( str );
  return 0;
}
