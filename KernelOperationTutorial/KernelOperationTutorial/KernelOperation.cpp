#include "KernelOperation.h"

void SharpenC(Mat& Input, Mat& Output)
{
	//accept unsigned char type of images ony
	CV_Assert(Input.depth() == CV_8U);

	Output.create(Input.size(), Input.type());
	
	int num_channels = Input.channels();
	int num_rows = Input.rows;
	int num_cols = Input.cols;

	for (int row = 1; row < (num_rows - 1); row++)
	{
		uchar* previous = Input.ptr<uchar>(row-1);
		uchar* current = Input.ptr<uchar>(row);
		uchar* next = Input.ptr<uchar>(row + 1);
		uchar* output = Output.ptr<uchar>(row);

		for (int col = num_channels; col < num_channels*(num_cols - 1); col++)
		{
			output[col] = saturate_cast<uchar>(5 * current[col] - (previous[col]+current[col-num_channels]+current[col+num_channels]+next[col]));
		}
	}

	Output.row(0).setTo(Scalar(0));
	Output.row(num_rows - 1).setTo(Scalar(0));
	Output.col(0).setTo(Scalar(0));
	Output.col(num_cols - 1).setTo(Scalar(0));

}

void SharpenFilter2D(Mat& Input, Mat& Output)
{

	Mat kern = (Mat_<char>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);

	filter2D(Input, Output, Input.depth(), kern);
}