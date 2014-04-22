#include "opencv2/opencv.hpp"
#include "stdio.h"
#include "math.h"

//#define IplImage *img;
IplImage* bit(IplImage* img, int x, int y){
	int h,w,H,W,i,j;
	float R,P,r,p,ang,k;
	double arr[1000][2];
	h = img->height;
	H = h*h;
	w = img->width;
	W = w*w;
	R = sqrt(H+W);
	ang = 4*asin(1);
	P =360;
	/*

	//printf("%f\n",R );
	i =0;
	for (float r = 0,k=0; r < R && p<P; k+=0.5)
	{
		p = (k*ang)/360 ; 
		r = x*cos(p) + y*sin(p);
		arr[i][0] = r;
		arr[i][1] = p;
		printf("%lf\t %lf \t %d\t %d\n",r,p,x,y );
		
	}
	j=i;
	for (int i = 0; i < j; ++i)
	{	
		if (arr[i][i]!=0)
		{

			printf(" i =    %d\n",i );
			printf("%lf", arr[i][i]);
		}
		
	}
*/
	return 0;

}


IplImage* bin(IplImage* img,int thres){
	CvScalar pix;
	int i,j,h,w;
	h = img->height;
	w = img->width;

	for (int i = 0; i < h; ++i)
	{
		for (int j  = 0; j < w; ++j)
		{
			pix = cvGet2D(img,i,j);
			if(pix.val[0]>thres){
				pix.val[0] = 255;
				bit(img,i,j);
				printf("%d\t %d\t",i,j );
				//printf("nonsense");
			}
			else pix.val[0] =0;
			cvSet2D(img,i,j,pix);
		}
	}
	
	return img;
}



int main(){
	IplImage* img =cvLoadImage("draw.png");
	IplImage* grey;
	int i,j,h,w;
	h = img->height;
	w = img->width;
	grey = cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,1);
	cvCvtColor(img,grey,CV_BGR2GRAY);

	grey = bin(grey,200);

	cvNamedWindow("win1",0);
	cvShowImage("win1",grey);
	cvWaitKey(0);

	return 0;
}