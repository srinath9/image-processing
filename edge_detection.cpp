
#include "opencv2/opencv.hpp"
#include <time.h>
 
IplImage* img;
IplImage* gray;
 
void function(int pos)            //function to be called by trackBar
{
 
	gray=cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,1);
	cvNamedWindow("win",0);       //create window in function
    int k,l;
	CvScalar pixel,pix,pix2;     //structure to store four values
	int i,j;
	  for(i=1;i<img->height-1;i++)
	{
		for(j=1;j<img->width-1;j++)
		{
			pixel.val[0]=255;
			cvSet2D(gray,i,j,pixel); 
			int min=255;
			int max=0;
			
			for(k=i-1;k<=i+1;k++)
			{
				for(l=j-1;l<=j+1;l++)
				{
					pix=cvGet2D(img,k,l);          //Getting pixel from loaded image
			/*   cvGet2D(<image name>,<x coord>,<y coord>)   */
					if(min>pix.val[0])
						min=pix.val[0];
					if(max<pix.val[0])
						max=pix.val[0];
				}
			}
			if((max-min)>=pos)
				pixel.val[0]=0;              //Threshold
			else
				pixel.val[0]=255;
            //  printf("HERE\n");
			cvSet2D(gray,i,j,pixel);            //Set pixel
			/*cvSet2D(<image name>,<x coord>,<y coord>, <name of pixel>) */
		}
	}
	
	cvShowImage("win",gray);
	cvReleaseImage(&gray);
	//cvWaitKey(0);
 
}
 
int main()
{
        CvCapture* capture=cvCreateCameraCapture(0);
        IplImage *frame,*output;
        //cvWaitKey(10000);
        
        int thresh=127;
        //cvNamedWindow("win",CV_WINDOW_AUTOSIZE);
        cvNamedWindow("window",CV_WINDOW_AUTOSIZE);
        frame = cvQueryFrame(capture);
		img=cvCreateImage(cvGetSize(frame),IPL_DEPTH_8U,1);
		//CvVideoWriter* writer = cvCreateVideoWriter("video.avi",CV_FOURCC('M','J','P','G'),30, cvGetSize(frame));
		/*  CvVideoWriter* writer= cvCreateVideoWriter(<filename>,<format>,<fps>,<size>)    */
         cvCreateTrackbar("Threshold","window",&thresh,255);
        while(1)
        {
                frame = cvQueryFrame(capture);
 
                if(!img)
                break;
 
                cvCvtColor(frame,img,CV_BGR2GRAY);
                //output = createbinary(frame);
                //cvWriteFrame( writer, frame );
                
                
 
                cvShowImage("window",img);
                function(thresh);
                //cvShowImage(win2,output);
                char c=cvWaitKey(33);
                if(c==27)
                        break;
        }
        //printf("%lld\n",fps);
        cvReleaseCapture(&capture);
 
        return 0;
}