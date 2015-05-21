#ifndef IMAGE_MANAGER
#define IMAGE_MANAGER

#include<string>
#include "Image.hpp"
#include <Iw2D.h>
#include <map>
#include <iterator>

class ImageManager{
private:
	std::map <std::string , Image> imageMap;


	Image value;
	std::string fileName;

public:
	Image getRes(std::string fileName)
	{/*
	Returns a reference type Image of the file specified.
	If this file is not yet loaded, it will be loaded.
	Duplicate files(determined by path) will not be loaded.
	Requires: fileName be a valid path/filename.
	*/
		std::pair<std::map<std::string, Image>::iterator, bool> res;
		Image i(fileName);//this is how you use constructors
		res = imageMap.insert(std::pair<std::string, Image>(fileName, i)); 
		return i;
	}
};
#endif