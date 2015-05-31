#ifndef PAIR
#define PAIR
#include<IwImage.h>

class pair{
public:
	int count;
	CIw2DImage * img;
	pair() :count(0){}
	pair(int x, CIw2DImage *y) : count(x), img(y){}
};

#endif