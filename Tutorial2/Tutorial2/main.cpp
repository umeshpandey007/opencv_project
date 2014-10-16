#include "opencv\cv.h"
#include "opencv\highgui.h"
#include <iostream>

using namespace std;
using namespace cv;


int main(int argc, char** argv)
{
	if (argc != 2)
	{
		cout << "Usage:Tutorial2.exe Image.jpg" << endl;
		return -1;
	}

	const string inputfile(argv[1]);
	const string outputfile("../test/gray_image.jpg");
	const string srcwindow("Original Image");
	const string dstwindow("GrayScale Image");

	Mat srcImage, dstImage;

	srcImage = imread(inputfile, CV_LOAD_IMAGE_COLOR);
	if (!srcImage.data)
	{
		cout << "Input image not specified" << endl;
		return -1;
	}

	cvtColor(srcImage, dstImage, CV_BGR2GRAY, 0);

	imwrite(outputfile, dstImage);

	namedWindow(srcwindow, WINDOW_AUTOSIZE);
	namedWindow(dstwindow, WINDOW_AUTOSIZE);

	imshow(srcwindow, srcImage);
	imshow(dstwindow, dstImage);

	waitKey(0);

	destroyAllWindows();

	return 0;

}