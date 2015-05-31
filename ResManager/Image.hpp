#ifndef IMAGE
#define IMAGE

#include <string>
#include <Iw2D.h>
#include <IwImage.h>
#include <map>
#include "Pair.hpp"

typedef std::map<std::string, pair>::iterator iter;
class ImageManager;

class Image{
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

	CIw2DImage * getCIw2DImage();
};

#endif