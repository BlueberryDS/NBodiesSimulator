#include "Imagemanager.hpp"

#include <string>
#include "Image.hpp"
#include <Iw2D.h>
#include <map>
#include <iterator>
#include <IwImage.h>

Image ImageManager::getRes(std::string fileName)
{
	/*
	Returns a reference type Image of the file specified.
	If this file is not yet loaded, it will be loaded.
	Duplicate files(determined by path) will not be loaded.
	Requires: fileName be a valid path/filename.
	*/
	std::pair<iter, bool> res = imageMap.insert(std::pair<std::string, pair>(fileName, pair()));

	if (res.second){
		res.first->second.img = Iw2DCreateImage(fileName.c_str());
	}

	return Image(res.first, this);
}

void ImageManager::certify(Image & baby)
{
	baby.data->second.count++;
}

void ImageManager::uncertify(Image & victim)
{
	victim.data->second.count--;
	if (!victim.data->second.count)
	{
		delete victim.getCIw2DImage();
		imageMap.erase(victim.data);
	}
}

ImageManager::~ImageManager(){
	for (iter i = imageMap.begin(); i != imageMap.end(); i++){
		delete i->second.img;
	}
}