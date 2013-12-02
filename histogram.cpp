#include "opencv2/opencv.hpp"
#include "stdio.h"
 
int main()
{
	IplImage* img,*gray,*binary;
	
	//Creating Image
	img=cvLoadImage("final1.jpg");         //Load image
	gray=cvCreateImage(cvGetSize(img),img->depth,1);
	binary=cvCreateImage(cvGetSize(img),img->depth,1);
	             
	/*  cvCreateImage(cvGetSize(<name of source image>),<depth of source image>,<no. of channels>)  */
	
    cvCvtColor(img,gray,CV_BGR2GRAY);
	CvScalar pixel,pix,pix2;     		//structure to store four values
	int array[256]={0};              	//storing the frequency of each shade
	
	cvNamedWindow("window",0);
	cvNamedWindow("win",0);
 
	int i,j,count=0,sum=0;
 
	for(i=0;i<gray->height;i++)
	{
		for(j=0;j<gray->width;j++)
		{
			pix=cvGet2D(gray,i,j);          //Getting pixel from loaded image
			/*   cvGet2D(<image name>,<x coord>,<y coord>)   */
			 
			array[(int)pix.val[0]]++;
		}
	}
	
	int total=gray->height*gray->width;
 
	while(1)
	{
		sum+=array[count];
		if(sum>=(total/2)  )
		break;
		count++;
	}
	int thresh=count;
	
	for(i=0;i<gray->height;i++)
	{
		for(j=0;j<gray->width;j++)
		{
			pix=cvGet2D(gray,i,j);          //Getting pixel from loaded image
			/*   cvGet2D(<image name>,<x coord>,<y coord>)   */
            if(pix.val[0]>thresh)
			pixel.val[0]=255;              //Threshold  on basis of median
			else
			pixel.val[0]=0;
			cvSet2D(binary,i,j,pixel);            //Set pixel
			/*cvSet2D(<image name>,<x coord>,<y coord>, <name of pixel>) */
		}
	}
	cvShowImage("window",gray);   //Show Image
	cvShowImage("win",binary); 
	cvWaitKey(0);                //Wait Key (Default is keyStroke)
	cvReleaseImage(&img);        //Release image
	cvDestroyWindow("window");   //Destroy window
}