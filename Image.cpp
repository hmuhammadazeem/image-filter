#include "Image.h"


Image::Image(FIBITMAP *file) {
	img = FreeImage_Clone(file);
	bytespp = FreeImage_GetLine(img) / FreeImage_GetWidth(img);
}

void Image::SaveImage(const char path[]) {
	FreeImage_Save(FIF_JPEG, img, path, 0);
}

void Image::GreyScale() {
	for (unsigned y = 0; y < FreeImage_GetHeight(img); y++) {
		BYTE *bits = FreeImage_GetScanLine(img, y);
		for (unsigned x = 0; x < FreeImage_GetWidth(img); x++) {
			float fWB = sqrt((bits[FI_RGBA_RED] * bits[FI_RGBA_RED] + bits[FI_RGBA_GREEN] * bits[FI_RGBA_GREEN] + bits[FI_RGBA_BLUE] * bits[FI_RGBA_BLUE]) / 3);
			bits[FI_RGBA_RED] = fWB;
			bits[FI_RGBA_GREEN] = fWB;
			bits[FI_RGBA_BLUE] = fWB;
			bits += bytespp;
		}
	}
}

void Image::Vintage() {
	for (unsigned y = 0; y < FreeImage_GetHeight(img); y++) {
		BYTE *bits = FreeImage_GetScanLine(img, y);
		for (unsigned x = 0; x < FreeImage_GetWidth(img); x++) {
			bits[FI_RGBA_ALPHA] = 198;
			bits += bytespp;
		}
	}
}