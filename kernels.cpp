#include "opencv2/opencv.hpp"
#include "stdio.h"
IplImage* img;

//erosion amd dilution

int margin(int i, int j){
	if (i>j){
		return 0;	}

	else return 255;

}

IplImage* greynum(){
	int thresh=200;
	CvScalar pix;
	int i,j,h,w,a,k;
	h = img->height;
	w = img->width;
	IplImage* grey;

	grey = cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,1);
	cvCvtColor(img,grey,CV_BGR2GRAY);
	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			pix = cvGet2D(grey,i,j);
			for (int k = 0; k < 1; ++k)
			{
				//printf("%lf\n",pix.val[k] );
				pix.val[k]=margin(pix.val[k],thresh);

			}
			cvSet2D(grey,i,j,pix);

		}
		/* code */
	}
	cvNamedWindow("win2",0);
	cvShowImage("win2",grey);
	cvWaitKey(0);

	return grey;

}

int main(){
	int i,j,h,w;
	IplImage* grey;
	img = cvLoadImage("drawing.png");
	cvNamedWindow("win",0);
	cvShowImage("win",img);
	

	CvScalar pix;

	h = img->height;
	w = img->width;

	grey = greynum();
	cvNamedWindow("win1",0);
	cvShowImage("win1",grey);
	cvWaitKey(0);
	return 0;
}