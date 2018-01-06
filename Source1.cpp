#include "Image.h"

using namespace std;


int main(int argc, char* argv[]) {

	FIBITMAP *img;
	//argv[1]: Path to the file to be loaded
	img = FreeImage_Load(FIF_JPEG, argv[1], 0);

	Image image(img);

	image.Vintage();

	//argv[2]: Path to the location to saved
	image.SaveImage(argv[2]);

	system("pause");
	return 0;
}