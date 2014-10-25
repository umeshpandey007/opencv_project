#pragma once
#include "opencv2\core\core.hpp"
#include "opencv2\imgproc\imgproc.hpp"

using namespace cv;

void SharpenC(Mat& Input, Mat& Output);

void SharpenFilter2D(Mat& Input, Mat& Output);