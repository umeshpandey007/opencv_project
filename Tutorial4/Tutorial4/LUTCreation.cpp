#include "LUTCreation.h"

uchar lut_8bit[256];

uchar* create_lut_8bit(int divide_width)
{

	for (int i = 0; i < 255; i++)
		lut_8bit[i] = (uchar)((i / divide_width)*divide_width);

	return lut_8bit;
}
