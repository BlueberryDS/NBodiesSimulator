#include<iostream>
#include<assert.h>
#include<Iw2D.h>
#include"ImageManager.hpp"

int main(){

	//Simple Unit Test

	std::cout << "===========================Does this work?=========================" << std::endl;

	//Please ensure that everything points to the correct place. This test did not account for the values of the program.
	
	{//Simple constuction and deconstruction of an ImageManager. This should not crash the program
		ImageManager myImageManager;
		if(!myImageManager.getMap().size() == 0) std::cout << "fail" << std::endl;
	}

	ImageManager myImageManagerForTesting;

	{//simple construction/deconstruction of an Image. This also should not crash the program.
		Image a;
		if (!myImageManagerForTesting.getMap().size() == 0) std::cout << "fail" << std::endl;
	}

	{//Copy constructor construction of an Image.
		Image a = myImageManagerForTesting.getRes("TestData\test-smily.png");
		//Here the manager should have one element loaded in it
		if (!myImageManagerForTesting.getMap().size() == 1) std::cout << "fail" << std::endl;
	}//it should not crash on deconstruction

	//here the image manager should have nothing loaded in it
	if (!myImageManagerForTesting.getMap().size() == 0) std::cout << "fail" << std::endl;

	{//Copy constructor construction of a 2 Images.
		Image a = myImageManagerForTesting.getRes("TestData\test-smily.png");
		Image b = myImageManagerForTesting.getRes("TestData\test-saddy.png");
		//Here the manager should have 2 elements loaded in it
		if (!myImageManagerForTesting.getMap().size() == 2) std::cout << "fail" << std::endl;
	}//it should not crash on deconstruction

	//here the image manager should have nothing loaded in it

	if (!myImageManagerForTesting.getMap().size() == 0) std::cout << "fail" << std::endl;;

	{//double initilization
		Image a = myImageManagerForTesting.getRes("TestData\test-smily.png");
		Image b = myImageManagerForTesting.getRes("TestData\test-smily.png");
		//Here the manager should have one element loaded in it
		if (!myImageManagerForTesting.getMap().size() == 1) std::cout << "fail" << std::endl;
	}//no crash plz

	//Nothing loaded in image manager here
	if (!myImageManagerForTesting.getMap().size() == 0) std::cout << "fail" << std::endl;

	{//Assignment Operator test
		Image a = myImageManagerForTesting.getRes("TestData\test-smily.png");
		Image b = myImageManagerForTesting.getRes("TestData\test-saddy.png");
		//Here the manager should have 2 elements loaded in it
		if (!myImageManagerForTesting.getMap().size() == 2) std::cout << "fail" << std::endl;
		a = b;
		//Here the image manager should have 1 element loaded.
		if (!myImageManagerForTesting.getMap().size() == 1) std::cout << "fail" << std::endl;
	}//it should not crash on deconstruction

	if (!myImageManagerForTesting.getMap().size() == 0) std::cout << "fail" << std::endl;
	//nothing should be loaded here

	{//equality operator test
		Image a = myImageManagerForTesting.getRes("TestData\test-smily.png");
		Image b = myImageManagerForTesting.getRes("TestData\test-saddy.png");

		if ((a == b))std::cout << "Fail" << std::endl;

		a = b;

		if (!(a == b))std::cout << "Fail" << std::endl;
	}

	//here a the image manager should have nothing loaded.
	
	while (true);

	return 0;
}