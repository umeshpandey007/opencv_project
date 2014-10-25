#include "opencv2\core\core.hpp"
#include "opencv2\highgui\highgui.hpp"
#include <iostream>
#include "LUTCreation.h"
#include "ImageReduce.h"

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
	if (argc != 3)
	{
		cout << "Usage: Tutorial4.exe Image.jpg divide_width" << endl;
	}
	int divide_width= atoi(argv[2]);
	const string inputFile(argv[1]);
	const string outputFileC("../test/reduce_imageC.jpg");
	const string outputFileIt("../test/reduce_imageIt.jpg");
	const string outputFileLut("../test/reduce_imageLut.jpg");
	const string outputFileRand("../test/reduce_imageRand.jpg");

	const uchar* const lookup_table = create_lut_8bit(divide_width);

	Mat inputImage;
	
	inputImage = imread(inputFile, CV_LOAD_IMAGE_COLOR);
	
	{

		double t = (double)getTickCount();

		Mat& outputImage = ScanImageAndReduceC(inputImage, lookup_table);

		t = ((double)getTickCount() - t) / getTickFrequency();
		cout << "Times passed in seconds for ScanImageAndReduceC: " << t << endl;

		imwrite(outputFileC, outputImage);
	}

	{
		double t = (double)getTickCount();

		Mat& outputImage = ScanImageAndReduceCvLut(inputImage, lookup_table);
		
		t = ((double)getTickCount() - t) / getTickFrequency();
		cout << "Times passed in seconds for ScanImageAndReduceCvLut: " << t << endl;


		imwrite(outputFileLut, outputImage);
	}

	{
		double t = (double)getTickCount();

		Mat& outputImage = ScanImageAndReduceIterator(inputImage, lookup_table);

		t = ((double)getTickCount() - t) / getTickFrequency();
		cout << "Times passed in seconds for ScanImageAndReduceIterator: " << t << endl;


		imwrite(outputFileIt, outputImage);
	}

	{
		double t = (double)getTickCount();

		Mat& outputImage = ScanImageAndReduceRandomAccess(inputImage, lookup_table);

		t = ((double)getTickCount() - t) / getTickFrequency();
		cout << "Times passed in seconds for ScanImageAndReduceRandomAccess: " << t << endl;


		imwrite(outputFileRand, outputImage);
	}


	return 0;

}