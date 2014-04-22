#include "opencv2/opencv.hpp"
#include "stdio.h"
int main(){
	cvNamedWindow("win",0);
	CvCapture* cap = cvCreateFileCapture("/media/Mydrive/4-3-IntroductiontoMatlab(2053).mp4");
	IplImage* img ;

	while(1){
		img = cvQueryFrame(cap);
		if (!img )
		{
			printf("bdsd\n");
			break;
		}
		cvShowImage("win",img);
		char c = cvWaitKey(33);
		if(c==27){
			break;
		}
	} 

	cvReleaseCapture(&cap);
	cvReleaseImage(&img);
	cvDestroyWindow("win");

	return 0;
}