
#include <iostream>
#include "opencv2/opencv.hpp" 
 
IplImage* img;
IplImage* gray;                   //Global declared images to be accessed by both functions
 
 
void function(int pos)            //function to be called by trackBar
{
	cvNamedWindow("win",0);       //create window in function
 
	CvScalar pixel,pix,pix2;     //structure to store four values
 
	int i,j;
 
	  for(i=0;i<img->height;i++)
	{
		for(j=0;j<img->width;j++)
		{
			pix=cvGet2D(img,i,j);          //Getting pixel from loaded image
			/*   cvGet2D(<image name>,<x coord>,<y coord>)   */
			 
			pixel.val[0]=pix.val[0]+pix.val[1]+pix.val[2];
			pixel.val[0]/=3;
			if(pixel.val[0]>pos)
			pixel.val[0]=255;              //Threshold
			else
			pixel.val[0]=0;
 
			cvSet2D(gray,i,j,pixel);            //Set pixel
			/*cvSet2D(<image name>,<x coord>,<y coord>, <name of pixel>) */
		}
	}
	cvShowImage("win",gray);
 
}
 
 
int main()
{
 
	//Creating Image
	img=cvLoadImage("final1.jpg");         //Load image
	gray=cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,1);               
 
	/*  cvCreateImage(cvGetSize(<name of source image>),<depth of source image>,<no. of channels>)  */
        int thresh;
	
	
	cvNamedWindow("window",0);
	//cvNamedWindow("win",0);
 
	int i,j;
	cvCreateTrackbar("Threshold","window",&thresh,255,function);
 
	/*  cvCreateTrackbar(<name of trackbar>,<name of window>,<address of thresholding variable>,<max value>,<callBack function>)  */
 
	cvShowImage("window",img);   //Show Image
	
	cvWaitKey(0);                //Wait Key (Default is keyStroke)
	cvReleaseImage(&img);        //Release image
	cvDestroyWindow("window");   //Destroy window
}