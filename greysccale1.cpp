#include "opencv2/opencv.hpp"
#include "stdio.h"
#define PIX(img,i,j,k) (((uchar *)img->imageData)[(i)*img->widthStep + (j)*img->nChannels + (k)])


int main(){
	int thresh=127,h,w,i,j;

	IplImage *img = cvLoadImage("p2.JPG");
	IplImage *grey = cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,1);
	IplImage *newname = cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,1);
	h = img->height;
	w=img->width;

	//cvCreateTrackbar("img","win",&thresh,255);
	cvCvtColor(img,grey,CV_BGR2GRAY);
	CvScalar pixel1;
	CvScalar pixel2;


		for (int i = 0; i < h; ++i)
		{
			for (int j = 0; i < w; ++j)
			{
					pixel1 = cvGet2D(grey,i,j);

					if (pixel1.val[0]>thresh)
					{
						printf("asdsa\n");
						//pixel1.val[0]=255;
					}

					else{
						//pixel1.val[0]=0;
					}

					//b = pixel.val[0];
					//g= pixel.val[1];
					//r  = pixel.val[2];
					cvSet2D(newname, i , j, pixel1);
			}
			/* code */
		}
		cvShowImage("win",newname);
		cvWaitKey(0);
	

	cvShowImage("win",grey);

	cvWaitKey(0);
	cvReleaseImage(&img);
	cvReleaseImage(&grey);
	cvReleaseImage(&newname);
	return 0;
}

/*function grey(i,j){

	;

	pixel = cvGet2D(img,i,j);

			//b = pixel.val[0];
			//g= pixel.val[1];
			//r  = pixel.val[2];
	cvSet2D(newname, i , j, pixel);

}*/