
# The MIT License (MIT)
#
# Copyright (c) 2017 Trevor Bakker
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restringiction, including without limitation the rights
# to use, copy, modify, merge, publish, distringibute, sublicense, and/or sell
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

#!/usr/bin/python
# Purpose: print all permutations of a stringing.  A very C-like python implementation

def swap( string, left, right ):
	string = list( string )
	string[left], string[right] = string[right], string[left]
	return ''.join(string)

def permute( string, i, length ):
	if i == length:
		print string;

	for j in range ( i, length ):
    		string = swap   ( string, i, j );
    		permute( string, i + 1, length );
    		string = swap   ( string, i, j );

def main():
        string = "ABCD"
        permute( string, 0, len( string ) );

if __name__ == '__main__':
        main()
