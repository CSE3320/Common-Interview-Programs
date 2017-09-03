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

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <math.h>

bool isOperator( const std::string & token )
{
  bool ret = false;
  static const std::string operators ="+-*/^";

  if ( token.length() == 1 ) 
  {
    ret = operators.find_first_of( token[0] ) != std::string::npos;
  }
  return ret;
}

int main ( int argc, char * argv[] )
{
  std::stack<int> operands;
  std::string inputString;

  while( 1 ) 
  {
    getline( std::cin, inputString );

    std::istringstream iss( inputString );
    std::string token;
    
    while( getline( iss, token, ' ' ) )
    {
      if( isOperator( token ) )
      {
          int second_operand  = operands.top( );
          operands.pop( );
          int first_operand = operands.top( );
          operands.pop( );

          if( token == "+" )
          {
            operands.push( first_operand + second_operand );
          }
          else if ( token == "-" )
          {
            operands.push( first_operand - second_operand );
          }
          else if ( token == "*" )
          {
            operands.push( first_operand * second_operand );
          }
          else if ( token == "/" )
          {
            operands.push( first_operand / second_operand );
          }
          else if ( token == "^" )
          {
            operands.push( pow( first_operand , second_operand ) );
          }
      } 
      else 
      {
        operands.push( std::stoi( std::string( token ) ) );
      }
    }
    std::cout << operands.top() << std::endl;
  }
  return 0;
}
