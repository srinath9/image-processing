#include "opencv2/opencv.hpp"
#include "stdio.h"


int main(){

	IplImage *img = cvLoadImage("final1.jpg");
	IplImage *grey = cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,1);

	cvCvtColor(img,grey,CV_BGR2GRAY);

	cvNamedWindow("win",0);
	cvShowImage("win",grey);
	cvWaitKey(0);
	cvReleaseImage(&img);
	cvReleaseImage(&grey);

	return 0;
}