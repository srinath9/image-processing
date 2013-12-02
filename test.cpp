#include "opencv2/opencv.hpp"

#include <cv.h>
#include <highgui.h>


int main(){

	IplImage *img =cvLoadImage("lna.jpg");
	cvNewWindow("image",1);
	cvShowImage("image",img);

	cvWaitKey(0);

}