#pragma once
#include <iostream>
#include "FreeImage.h"


class Image {
private:
	FIBITMAP *img;
	int bytespp;
public:

	Image(FIBITMAP *file);
	void SaveImage(const char path[]);

	//Filter functions
	void GreyScale();
	void Vintage();
	void Blur();
	void GuassianBlur();


};
