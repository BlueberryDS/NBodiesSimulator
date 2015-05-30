#ifndef IMAGE_MANAGER
#define IMAGE_MANAGER

#include<string>
#include "Image.hpp"
#include <Iw2D.h>
#include <map>
#include <iterator>
#include <IwImage.h>

class ImageManager{
private:


	std::map <std::string, pair> imageMap;
	void uncertify(Image & victim);
	/*
	Consumes an Image & victim, and removes it from the map
	*/
	void certify(Image & child);
	
public:
	friend class Image;
	Image getRes(std::string fileName);
	/*
	Returns a reference type Image of the file specified.
	If this file is not yet loaded, it will be loaded.
	Duplicate files(determined by path) will not be loaded.
	Requires: fileName be a valid path/filename.
	*/

	};
#endif