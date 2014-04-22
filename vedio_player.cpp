
#include "stdafx.h"
#include <stdio.h>
#include <highgui.h>
#include <cv.h>
#include <cxcore.h>
#define PIX(img,i,j,k) (((uchar*)img->imageData)[i*img->widthStep+j*img->nChannels+k])
CvCapture *capture=cvCreateFileCapture("video.mp4");
void setCap(int k)
{
cvSetCaptureProperty(capture,CV_CAP_PROP_POS_FRAMES,k);
}
int main()
{
IplImage *frame;
int k=0;
cvNamedWindow("image",0);
int x=cvGetCaptureProperty(capture,CV_CAP_PROP_FRAME_COUNT);

while(1)
{

frame=cvQueryFrame(capture);
cvCreateTrackbar("time","image",&k,x,setCap);

//frame2=cvQueryFrame(capture);
//cvCvtColor(frame,frame2,CV_RGB2GRAY);
if(!frame)
break;
cvShowImage("image",frame);
cvWaitKey(33);
k++;

}

cvDestroyWindow("image");
}
