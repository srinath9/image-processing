#include "opencv2/opencv.hpp"
#include "stdio.h"

#define PIX(img,i,j,k) (((uchar *)img->imageData)[(i)*img->widthStep + (j)*img->nChannels + (k)])

int main(){

	long long int h,w,i,j,k;

	IplImage *img = cvLoadImage("p2.JPG");

	h=img->height;
	w=img->width;






	return 0;
}