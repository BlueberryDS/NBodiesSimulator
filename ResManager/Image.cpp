#include "Image.hpp"

/*This file contains the definitions of various constructors for the Image class
Note that 0 is the default value of width and height, and that NULL is the default value of file.
*/
Image::Image()
{
	fileName = "";
}

Image::Image(char *fileName)
{
	this->fileName = fileName;
	handle = Iw2DCreateImage(fileName);
}

Image::~Image()
{//destructor
	delete handle;
	delete fileName;
}

Image::Image(const Image & other)
{
	/*
	Copy Constructor
	Copys other to itself, during the construction process of the object.
	e.g
	Image b;
	Image a = b;
	*/
}

Image& Image::operator = (const Image & other)
{
	/*
	Assignment operator
	Copies other to itself, unregistering whatever image was already in the object
	e.g.
	Image a("file1"), b("file2");
	a = b;
	*/
	delete this->handle;
	delete this->fileName;
	Image& output = other;
	return output;

}

bool Image::operator==(const Image & other)
{/*
Equality operator
Compares two images and returns true if they are equal
*/
	return this->fileName == other.fileName && this->handle == other.handle;
}
