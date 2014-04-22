#include "opencv2/opencv.hpp"
#include "stdio.h"



int main() {
	cvNamedWindow("win",0);
	CvCapture* capture = cvCreateFileCapture("/media/Mydrive/4-3-IntroductiontoMatlab(2053).mp4");
	IplImage* frame;
	while(1) {
		
		frame = cvQueryFrame( capture );
		if( !frame ) break;
		cvShowImage( "win", frame );
		char c = cvWaitKey(33);
		if( c == 27 ) break;
		}
	cvReleaseCapture( &capture );	
	cvDestroyWindow( "win" );
}
