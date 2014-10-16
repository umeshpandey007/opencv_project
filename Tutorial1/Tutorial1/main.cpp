
#include <iostream>
#include "opencv2\core\core.hpp"
#include "opencv2\highgui\highgui.hpp"

using  namespace std;
using namespace cv;

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		cout << "usage:Tutorial1.exe Image.jpg"<<endl;
		return -1;
	}
	Mat image;
	const string filen(argv[1]);
	const string window_name("Tutorial1");

	image = imread(filen, CV_LOAD_IMAGE_COLOR);

	if (!image.data)
	{
		cout << "No image specified" << endl;
		return -1;
	}

	namedWindow(window_name, WINDOW_AUTOSIZE);
	imshow(window_name, image);

	waitKey(0);

	destroyWindow(window_name);

	return 0;
}