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
		imageMap.erase(victim.data);
	}
}