#include "ImageReduce.h"

Mat& ScanImageAndReduceC(Mat& I,const uchar* const lut)
{
	// accept only char type matrices
	CV_Assert(I.depth() != sizeof(uchar));

	int num_channels = I.channels();
	int num_rows = I.rows;
	int num_cols = num_channels * I.cols;

	if (I.isContinuous())
	{
		num_cols = num_rows * num_cols;
		num_rows = 1;
	}

	uchar* p;
	for (int row = 0; row < num_rows; row++)
	{
		p = I.ptr<uchar>(row);

		for (int col = 0; col < num_cols; col++)
		{
			p[col] = lut[p[col]];
		}
	}

	return I;
}


Mat& ScanImageAndReduceIterator(Mat& I, const uchar* const lut)
{
	// accept only char type matrices
	CV_Assert(I.depth() != sizeof(uchar));

	int num_channels = I.channels();

	switch (num_channels)
	{
		case 1:
		{
			MatIterator_<uchar> it, end;
			for ( it = I.begin<uchar>(), end = I.end<uchar>(); it != end; ++it)
			{
				*it = lut[*it];
			}
			break;
		}

		case 3:
		{
			MatIterator_<Vec3b> it, end;
			for (it = I.begin<Vec3b>(), end = I.end<Vec3b>(); it != end; ++it)
			{
				(*it)[0] = lut[(*it)[0]];
				(*it)[1] = lut[(*it)[1]];
				(*it)[2] = lut[(*it)[2]];
			}
			break;
		}

		default:
		{
			CV_Assert("Num channels not supported");
			break;
		}

	}

	return I;
}

Mat& ScanImageAndReduceRandomAccess(Mat& I, const uchar* const lut)
{
	// accept only char type matrices
	CV_Assert(I.depth() != sizeof(uchar));

	int num_channels = I.channels();

	switch (num_channels)
	{
		case 1:
		{

			for (int i = 0; i < I.rows; i++)
			{
				for (int j = 0; j < I.cols; j++)
				{
					I.at<uchar>(i, j) = lut[I.at<uchar>(i, j)];
				}
			}
			break;
		}

		case 3:
		{
			
			Mat_<Vec3b> _I = I;
			
			for (int i = 0; i < I.rows; i++)
			{
				for (int j = 0; j < I.cols; j++)
				{
					_I(i, j)[0] = lut[_I(i, j)[0]];
					_I(i, j)[1] = lut[_I(i, j)[1]];
					_I(i, j)[2] = lut[_I(i, j)[2]];
				}
			}

			
			
			break;
		}

		default:
		{
			CV_Assert("Num channels not supported");
			break;
		}

	}

	
	return I;
}


Mat& ScanImageAndReduceCvLut(Mat& I, const uchar* const lut)
{

	Mat RedLut(1, 256, CV_8U, (void*)lut);

	LUT(I, RedLut, I);
	
	return I;
}
