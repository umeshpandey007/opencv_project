#pragma once

#include "opencv2\core\core.hpp"

using namespace cv;

Mat& ScanImageAndReduceC(Mat& I, const uchar* const lut);

Mat& ScanImageAndReduceIterator(Mat& I, const uchar* const lut);

Mat& ScanImageAndReduceCvLut(Mat& I, const uchar* const lut);

Mat& ScanImageAndReduceRandomAccess(Mat& I, const uchar* const lut);