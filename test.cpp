#include "opencv2/opencv.hpp"

int main(){
	IplImage* img = cvLoadImage("final1.jpg",1);
	cvNamedWindow("win",0);
	cvShowImage("win",img);
	cvWaitKey(0);





return 0;
}