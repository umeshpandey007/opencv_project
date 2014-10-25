#include <iostream>
#include "opencv2\core\core.hpp"
#include "opencv2\highgui\highgui.hpp"
#include "KernelOperation.h"

using namespace std;
using namespace cv;



int main(int argc, char** argv)
{
	if (argc != 2)
	{
		cout << "Usage: KernelOperationTutorial.exe inputImage.jpg" << endl;
		return -1;
	}

	Mat inputImage, outputImageC,outputImageLib;
	const string inputFile(argv[1]);
	const string outputFileC("../test/SmoothC.jpg");
	const string outputFileLib("../test/Smoothfilter.jpg");

	inputImage = imread(inputFile, CV_LOAD_IMAGE_COLOR);

	{
		double t = (double)getTickCount();

		SharpenC(inputImage, outputImageC);

		t = ((double)getTickCount() - t) / getTickFrequency();
		cout << "Times passed in seconds for SharpenC: " << t << endl;
	}

	{
		double t = (double)getTickCount();

		SharpenFilter2D(inputImage, outputImageLib);

		t = ((double)getTickCount() - t) / getTickFrequency();
		cout << "Times passed in seconds for SharpenFilter2D: " << t << endl;
	}


	namedWindow("Input", WINDOW_AUTOSIZE);
	namedWindow("OutputC", WINDOW_AUTOSIZE);
	namedWindow("OutputLib", WINDOW_AUTOSIZE);

	imshow("Input", inputImage);
	imshow("OutputC", outputImageC);
	imshow("OutputLib", outputImageC);

	waitKey(0);

	destroyAllWindows();

}