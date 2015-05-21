#include "Image.h"
#include "ImageManager.h"
#include <string.h>

/*This file contains the definitions of various constructors for the Image class
Note that 0 is the default value of width and height, and that NULL is the default value of file.
*/
Image::Image()
{
	Image i = new Image();
	i.width = 0;
	i.height = 0;
	i.file = NULL;
}

Image::Image(int givenWidth, int givenHeight)
{
	Image i = new Image();
	i.width = givenWidth;
	i.height = givenHeight;
	i.file = NULL;
}
Image::Image(FILE * f)
{
	Image i = new Image();
	i.width = 0;
	i.height = 0;
	i.file = f;
	//std::string fileName = 

}
Image::Image(std::string fileName)
{
	Image i = new Image();
	i.width = 0;
	i.height = 0;
	i.file = fopen(fileName.c_str, "r");
	ImageManager::getRes(fileName, i);
}