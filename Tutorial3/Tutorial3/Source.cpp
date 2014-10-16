#include "opencv2\core\core.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, void**argv)
{
	/* Invokes default constructor*/
	Mat A;

	/*Invokes constructor
	Mat(int rows, int cols, int type);
	*/

	Mat B(2, 3, CV_8UC3);

	/*Invokes constructor
	Mat(Size size, int type);
	*/

	Mat C(Size(4, 5), CV_8UC3);

	/*Invokes constructor
	Mat(int rows, int cols, int type, const Scalar& s);
	*/

	Mat D(2, 3, CV_8UC3, Scalar(0, 0, 255));

	/*Invokes constructor
	Mat(Size size, int type, const Scalar& s);
	*/

	Mat E(Size(3,2), CV_8UC3, Scalar::all(128));

	Mat Ea(Size(3, 2), CV_8UC3, Scalar(128));

	/*Invokes constructor: n dimensional matrices
	Mat(int ndims, const int* sizes, int type);
	*/

	int sz[4] = { 2, 3, 2, 2 };
	Mat F(4,sz,CV_8UC2);

	/*Invokes constructor: n dimensional matrices
	Mat(int ndims, const int* sizes, int type, const Scalar& s);
	*/
	int sz1[4] = { 2, 3, 2, 2 };
	const CvScalar scVals = { 1, 5 };
	
	Mat G(4, sz1, CV_32FC2, Scalar(scVals));

	/* Copy constructor*/

	Mat H(E);

	/*constructor for matrix headers pointing to user-allocated data*/
	/*
	Mat(int rows, int cols, int type, void* data, size_t step=AUTO_STEP);
	*/
	int user_data[5] = { 0x1234cdba, 2, 3, 4, 5 };

	Mat I(2, 3, CV_8UC3, user_data);

	/*constructor for matrix headers pointing to user-allocated data*/
	/*
	Mat(Size size, int type, void* data, size_t step=AUTO_STEP);
	*/

	Mat J(Size(2, 3), CV_8UC3, user_data);

	/*constructor for matrix headers pointing to user-allocated data*/
	/*
	Mat(int ndims, const int* sizes, int type, void* data, const size_t* steps=0);
	*/

	int sz2[3] = { 2, 2, 3 };

	Mat K(3, sz2, CV_8UC2, user_data);

	/*
	Mat(const Mat& m, const Range& rowRange, const Range& colRange=Range::all());
	*/

	Mat L(E, Range(1, 2), Range(1, 1));

	return 0;


}