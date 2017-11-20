/*
* Main.cpp
*
* Version information
* Author: Dr. Shane Wilson
* Date:09/11/2017
* Description: Array class 
*
///**************************************************************************
// * (C) Copyright 1992-2017 by Deitel & Associates, Inc. and               *
// * Pearson Education, Inc. All Rights Reserved.                           *
// *                                                                        *
// * DISCLAIMER: The authors and publisher of this book have used their     *
// * best efforts in preparing the book. These efforts include the          *
// * development, research, and testing of the theories and programs        *
// * to determine their effectiveness. The authors and publisher make       *
// * no warranty of any kind, expressed or implied, with regard to these    *
// * programs or to the documentation contained in these books. The authors *
// * and publisher shall not be liable in any event for incidental or       *
// * consequential damages in connection with, or arising out of, the       *
// * furnishing, performance, or use of these programs.                     *
// **************************************************************************/

#include <iostream>
#include <iomanip>
#include <stdexcept> 

#include "Array.h" // Array class definition
using namespace std;

// default constructor for class Array (default size 10)
Array::Array( int arraySize )
   : size( arraySize > 0 ? arraySize : 
        throw invalid_argument( "Array size must be greater than 0" ) ),
     ptr( new int[ size ] )
{
   for ( size_t i = 0; i < size; ++i )
      ptr[ i ] = 0; // set pointer-based array element
} // end Array default constructor

// copy constructor for class Array;
Array::Array(const Array &arrayToCopy) :
	size(arrayToCopy.size),	ptr(new int[size]) {

	//Loop through the arrayToCopy and copy the elements into the new array
	for (size_t i = 0; i < size; i++)
		ptr[i] = arrayToCopy.ptr[i]; //copy into our array
}

//Move constructor
//Must receive an ravlue reference to an array
Array::Array(Array &&arrayToMove) noexcept
	: size(arrayToMove.size), //Move arrayToMove's size to new array
	ptr(arrayToMove.ptr) //move arrayToMove's ptr to new array
{
	std::cout << "Array move constructor called " << std::endl;

	//Indicate that arrayToMove is now empty
	arrayToMove.size = 0;
	arrayToMove.ptr = nullptr;
}

// destructor for class Array
Array::~Array()
{
   //Free the allocated memory
	delete[] ptr; //Release the memory for the pointer based array
	ptr = nullptr;
} // end destructor

// overloaded assignment operator
//const return to prevent (a1 = a2) = a3
const Array &Array::operator=(const Array &right) {
	//Check for self assignment (a1=a1)
	if (&right != this) {
		//For arrays of different sizes, deallocate original
		//Left-side array, then allocate new left side array
		if (size != right.size) {
			//deallocate this array
			delete[] ptr;
			size = right.size; //resize the object
			ptr = new int[size]; //Create new array of ints matching right array size
		}
		for(size_t i = 0; i <size; i++)
			ptr[i] = right.ptr[i]; //copy into our array
		}
	return *this; 
}

//Move assignment operator
Array &Array::operator=(Array &&arrayToMove) noexcept {
	if (&arrayToMove != this) //avoid self-assignment
	{
		delete[] ptr;
		size = arrayToMove.size; //Resize this object
		ptr = arrayToMove.ptr; //Move arrayToMove's ptr to new array

		//Clean up arrayToMove
		arrayToMove.size = 0;
		arrayToMove.ptr = nullptr;
	}
	return *this;
}

// return number of elements of Array
size_t Array::getSize() const
{
	return size; // number of elements in Array
} // end function getSize

// determine if two Arrays are equal and
// return true, otherwise return false
bool Array::operator==( const Array &right ) const
{
   if ( size != right.size )
      return false; // arrays of different number of elements

   for ( size_t i = 0; i < size; ++i )
      if ( ptr[ i ] != right.ptr[ i ] )
         return false; // Array contents are not equal

   return true; // Arrays are equal
} // end function operator==

// overloaded subscript operator for non-const Arrays;
// reference return creates a modifiable lvalue
int &Array::operator[]( int subscript )
{
   // check for subscript out-of-range error
   if ( subscript < 0 || subscript >= size )
      throw out_of_range( "Subscript out of range" );

   return ptr[ subscript ]; // reference return
} // end function operator[]

// overloaded subscript operator for const Arrays
// const reference return creates an rvalue
int Array::operator[]( int subscript ) const
{
   // check for subscript out-of-range error
   if ( subscript < 0 || subscript >= size )
      throw out_of_range( "Subscript out of range" );

   return ptr[ subscript ]; // returns copy of this element
} // end function operator[]

// overloaded input operator for class Array;
// inputs values for entire Array
istream &operator>>( istream &input, Array &a )
{
   for ( size_t i = 0; i < a.size; ++i )
      input >> a.ptr[ i ];

   return input; // enables cin >> x >> y;
} // end function 

// overloaded output operator for class Array 
ostream &operator<<( ostream &output, const Array &a )
{
   size_t i;

   // output private ptr-based array 
   for ( i = 0; i < a.size; ++i )
   {
      output << setw( 12 ) << a.ptr[ i ];

      if ( ( i + 1 ) % 4 == 0 ) // 4 numbers per row of output
         output << endl;
   } // end for

   if ( i % 4 != 0 ) // end last line of output
      output << endl;

   return output; // enables cout << x << y;
} // end function operator<<
