#include "Image.hpp"
#include "ImageManager.hpp"

/*This file contains the definitions of various constructors for the Image class
Note that 0 is the default value of width and height, and that NULL is the default value of file.
*/
Image::Image()
{
	data = NULL;
	parent = NULL;
}

Image::~Image()
{//destructor
	parent->uncertify(*this);
}

Image::Image(iter givenData, ImageManager * givenParent)
{
	data = givenData;
	parent = givenParent;
	parent->certify(*this);
}

Image::Image(const Image & other)
{
	/*
	Copy Constructor
	*/
	data = other.data;
	parent = other.parent;
	parent->certify(*this);
}

Image& Image::operator = (const Image & other)
{
	/*
	Assignment operator
	*/
	parent->uncertify(*this);
	data = other.data;
	parent = other.parent;
	parent->certify(*this);
	return *this;

}

bool Image::operator==(const Image & other)
{/*
Equality operator
Compares two images and returns true if they are equal
*/
	return data == other.data;
}
