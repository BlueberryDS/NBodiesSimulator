#ifndef IMAGE
#define IMAGE



class Image{
	//Implementation fields go here. (please remove these tages when done)
protected:
	//please define/store the data type used to hold a pointer/reference to the image here.
	//This is part of the interface. You do not need to create a setter/getter functions for this.
public:
	Image();
	/*
	Default Constructor
	Sets all fields to NULL or as appropriate.
	*/

	Image(/*insert nessessary arguments*/);
	/*
	(rewrite this documentation when done)
	Initializes a image object so that it's ready to go. Arguments could be the fields of the object
	for example.
	This function lets you do nice syntax things like this. Imagine if we had a posn object

	posn a(1,2);
	*/

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
