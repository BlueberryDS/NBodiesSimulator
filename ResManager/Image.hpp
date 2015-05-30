#ifndef IMAGE
#define IMAGE

#include <string>
#include <Iw2D.h>
#include <IwImage.h>
#include <map>
#include "Pair.h"

typedef std::map<std::string, pair>::iterator iter;
class ImageManager;

class Image{
	//Implementation fields go here. (please remove these tags when done)
	
protected:
	//please define/store the data type used to hold a pointer/reference to the image here.
	//This is part of the interface. You do not need to create a setter/getter functions for this.
	ImageManager * parent;
	iter data;
public:
	friend class ImageManager;

	Image();
	/*
	Default Constructor
	Sets all fields to NULL or as appropriate.
	*/

	Image(iter givenData, ImageManager * givenParent);

	~Image();
	/* Destructor for image*/

	Image(const Image & other);
	/*
	Copy Constructor
	Copys other to itself, during the construction process of the object.
	e.g
		Image b;
		Image a = b;
	*/

	Image& operator= (const Image & other);
	/*
	Assignment operator
	Copies other to itself, unregistering whatever image was already in the object
	e.g.
		Image a("file1"), b("file2");
		a = b;
	*/

	bool operator==(const Image & other);
	/*
	Equality operator
	Compares two images and returns true if they are equal
	*/
};

#endif