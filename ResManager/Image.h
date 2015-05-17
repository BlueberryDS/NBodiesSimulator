#ifndef IMAGE
#define IMAGE


class Image{
	//Implementation fields go here. (please remove these tags when done)
	int width, height; //dimensions in pixels of the Image
	
protected:
	FILE * file;
	//please define/store the data type used to hold a pointer/reference to the image here.
	//This is part of the interface. You do not need to create a setter/getter functions for this.
public:
	Image();
	/*
	Default Constructor
	Sets all fields to NULL or as appropriate.
	*/

	Image(int givenWidth, int givenHeight) //this constructor may not be necessary
	{/* Initializes an image object. Arguments are the images dimensions */
		width = givenWidth;
		height = givenHeight;
		file = NULL;
	}

	 
	Image(FILE * f)
	{
		file = f;
	}

	Image(std::string fileName)
	{
		file = fopen(fileName.c_str, "r");
	}

	~Image()
	{/* Destructor for image*/
		delete this;
	}

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

	
};

#endif