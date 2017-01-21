#!/usr/bin/python

# The MIT License (MIT)
#
# Copyright (c) 2016 Trevor Bakker
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
#
# Purpose: Demonstrate implementing fibonacci recursively and iteratively 
#          This uses the classic start value of 1.  Starting from 0
#           just requires changing the n_minus_one_value


def fibonacci_recursive( number ):
	if number < 3:
		return 1;
	else:
		return fibonacci_recursive( number - 1 ) + fibonacci_recursive( number - 2 );
		
	

def fibonacci_iterative( number ):
	n_value           = 1;
	n_minus_one_value = 1;
	value             = 1;
	for i in range( 2, number ):
		value             = n_value + n_minus_one_value;
		n_minus_one_value = n_value;
		n_value           = value;

	return value;

def main():
	print "Calculating the first ten fibonacci numbers recursively"
	for number in range(1,10):
		print( fibonacci_recursive( number ) );	

	print "\nCalculating the first ten fibonacci numbers iteratively"
	for number in range(1,10):
		print( fibonacci_iterative( number ) );	

if __name__ == '__main__':
        main()


