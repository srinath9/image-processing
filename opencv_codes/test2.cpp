#include "opencv2/opencv.hpp"
#include "stdio.h"

#define PIX(img,i,j,k) (((uchar *)img->imageData)[(i)*img->widthStep + (j)*img->nChannels + (k)])


int main(){
	long long int rsum=0,gsum=0,bsum=0,h,w,i,j;
	IplImage *img= cvLoadImage("p2.JPG");
	cvNamedWindow("win",0);
	cvShowImage("win",img);

	cvNamedWindow("win1",0);
	cvShowImage("win1",img);

	cvNamedWindow("win2",0);
	cvShowImage("win2",img);

	cvWaitKey(0);
	h = img->height;
	w = img->width;
	printf("here \n");
	printf("%lld \n",w);
	for(i=0;i<h;i++){
		for(j=0;j<w;j++){

			rsum += PIX(img,i,j,0);
			bsum += PIX(img,i,j,1);
			gsum += PIX(img,i,j,2);

		}
	}

	cvReleaseImage(&img);
	printf("%lld \n",rsum/(h*w));
	printf("%lld \n",gsum/(h*w));
	printf("%lld \n",bsum/(h*w));

	scanf("%lld",&i);

}


//sairavitejaiitkgp@gmail.com