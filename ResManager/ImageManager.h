#ifndef IMAGE_MANAGER
#define IMAGE_MANAGER

#include<string>
#include "Image.h"

class ImageManager{
private:
	//feilds needed for implementation go here...
public:
	Image getRes(std::string fileName);
	/*
	Returns a reference type Image of the file specified.
	If this file is not yet loaded, it will be loaded.
	Duplicate files(determined by path) will not be loaded.
	Requires: fileName be a valid path/filename.
	*/
};

#endif