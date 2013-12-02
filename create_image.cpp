#include "opencv2/opencv.hpp"
#include "stdio.h"

int main(){
	long long int h,w,i,j;

	IplImage *img = cvLoadImage("p2.JPG");

	IplImage *newname ;
	newname=cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,3);
	cvNamedWindow("nw",0);
	cvShowImage("nw",img);
	h = img->height;
	w = img->width;
	CvScalar pixel;
	printf("%lld %lld\n",h,w );
	for(i=0;i<h;i++){
		for (int j = 0; j < w; ++j)
		{
			pixel = cvGet2D(img,i,j);

			//b = pixel.val[0];
			//g= pixel.val[1];
			//r  = pixel.val[2];
			cvSet2D(newname, h-i-1 , w-j-1, pixel);
		}

	}
	cvNamedWindow("new1",0);
	cvShowImage("new1",newname);
	cvWaitKey(200);
	cvReleaseImage(&img);
	cvReleaseImage(&newname);
	cvWaitKey(0);


	return 0;
}