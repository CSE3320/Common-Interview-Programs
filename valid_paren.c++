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

/*

  Given a string containing just the characters '(', ')', '{', '}', '[' and ']', 
  for example, "[{()}]", you need to write a function which will check validity 
  of such an input string, function may be like this: 

   bool isValid(char* s); 

  The brackets have to close in the correct order, for example "()" and "()[]{}" 
   are all valid but "(]", "([)]" and "{{{{" are not.

*/
#include <string>
#include <map>
#include <stack>
#include <iostream>

typedef std::map< std::string, std::string > open_close_map_type;

/*
  Only handles string with lengths a multiple of 2
  \TODO: Fix it so odd length strings with letters and numbers count
*/

bool isValid( std::string str )
{
  open_close_map_type open_close_map;
  std::stack<std::string> open_close_stack;

  open_close_map["["] = "]";
  open_close_map["("] = ")";
  open_close_map["{"] = "}";

  int i;
  for( i = 0; i < str.length()/2; i++ )
  {
    open_close_stack.push( std::string(1,str[i]) ); 
  }

  for( i; i < str.length(); i++ )
  {
    std::string token = open_close_stack.top();
    open_close_stack.pop();
   
    if( open_close_map[token] != std::string(1, str[i]))
    {
      std::cout << token << " does not match "<< std::string(1,str[i]) << std::endl;
      return false;
    }
  }

  return true; 
}

int main ( void ) 
{
  std::cout<< "isValid: "<< isValid("{{}}")<<std::endl;
  std::cout<< "isValid: "<< isValid("{[]}")<<std::endl;
  std::cout<< "isValid: "<< isValid("{[}")<<std::endl;
  std::cout<< "isValid: "<< isValid("{[{{{")<<std::endl;
  return 0;
}
