#include<iostream>
#include<assert.h>
#include<Iw2D.h>
#include"ImageManager.hpp"

int main(){

	//I can't do in-depth tests yet because your code doesn't work enough yet.....
	//None of this will compile until everything is implemented.
	//These are just usage examples


	//Please ensure that everything points to the correct place. This test did not account for the values of the program.
	
	{//Simple constuction and deconstruction of an ImageManager. This should not crash the program
		ImageManager myImageManager;
	}

	ImageManager myImageManagerForTesting;

	{//simple construction/deconstruction of an Image. This also should not crash the program.
		Image a;
	}

	{//Copy constructor construction of an Image.
		Image a = myImageManagerForTesting.getRes("TestData\test-smily.png");
		//Here the manager should have one element loaded in it
	}//it should not crash on deconstruction

	//here the image manager should have nothing loaded in it

	{//Copy constructor construction of a 2 Images.
		Image a = myImageManagerForTesting.getRes("TestData\test-smily.png");
		Image b = myImageManagerForTesting.getRes("TestData\test-saddy.png");
		//Here the manager should have 2 elements loaded in it
	}//it should not crash on deconstruction

	//here the image manager should have nothing loaded in it

	{//double initilization
		Image a = myImageManagerForTesting.getRes("TestData\test-smily.png");
		Image b = myImageManagerForTesting.getRes("TestData\test-smily.png");
		//Here the manager should have one element loaded in it
	}//no crash plz

	//Nothing loaded in image manager here

	{//Assignment Operator test
		Image a = myImageManagerForTesting.getRes("TestData\test-smily.png");
		Image b = myImageManagerForTesting.getRes("TestData\test-saddy.png");
		//Here the manager should have 2 elements loaded in it
		a = b;
		//Here the image manager should have 1 element loaded.
	}//it should not crash on deconstruction

	//nothing should be loaded here

	{//equality operator test
		Image a = myImageManagerForTesting.getRes("TestData\test-smily.png");
		Image b = myImageManagerForTesting.getRes("TestData\test-saddy.png");

		assert(!(a == b));

		a = b;

		assert(a == b);
	}

	//here a the image manager should have nothing loaded.

	return 0;
}