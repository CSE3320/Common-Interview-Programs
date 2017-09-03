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


#include <sstream>
#include <iostream>
#include <algorithm>
#include <fstream>

int main ( int argc, char *argv[] )
{
   // open file
   std::fstream datafile(argv[1], std::ios_base::in);

   std::string firsttoken;
   std::string secondtoken;
   std::string str;

   while (std::getline( datafile, str ))
   {

     std::string firsttoken;
     std::string secondtoken;
     std::istringstream iss( str );

     // use the comma as a delimiter
     getline( iss, firsttoken, ',' );
     getline( iss, secondtoken );

     // remove the quotes and spaces
     firsttoken.erase( std::remove( firsttoken.begin(), firsttoken.end(), '"' ), firsttoken.end() );
     firsttoken.erase( std::remove( firsttoken.begin(), firsttoken.end(), ' ' ), firsttoken.end() );
     secondtoken.erase( std::remove( secondtoken.begin(), secondtoken.end(), '"' ), secondtoken.end() );
     secondtoken.erase( std::remove( secondtoken.begin(), secondtoken.end(), ' ' ), secondtoken.end() );

     // convert line to lowercase
     std::transform(firsttoken.begin(), firsttoken.end(), firsttoken.begin(), ::tolower);
     std::transform(secondtoken.begin(), secondtoken.end(), secondtoken.begin(), ::tolower);

     // call is permutation, output if pattern
     if (is_permutation(firsttoken.begin(), firsttoken.end(),secondtoken.begin())) 
     {
        std::cout<<"Valid Pattern"<<std::endl;
     } 
     else 
     { 
       std::cout<<"Invalid Pattern"<<std::endl; 
     }
   }
   return 0;
} 

