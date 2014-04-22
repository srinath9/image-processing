#include "opencv2/opencv.hpp"

<<<<<<< HEAD
int main(){
	IplImage* img = cvLoadImage("final1.jpg",1);
	cvNamedWindow("win",0);
	cvShowImage("win",img);
	cvWaitKey(0);
   




return 0;
=======
#include <cv.h>
#include <highgui.h>


int main(){

	IplImage *img =cvLoadImage("lna.jpg");
	cvNewWindow("image",1);
	cvShowImage("image",img);

	cvWaitKey(0);

>>>>>>> 740a460be5c6b62bab6452e8032caab1e6495f8f
}