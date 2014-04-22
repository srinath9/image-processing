#include <iostream>
#include "opencv2/opencv.hpp"
 
 
int main()
{
        CvCapture* capture=cvCreateCameraCapture(0);
        IplImage *frame,*output;
        //int k=cvWaitKey(3000);
        
 
        cvNamedWindow("win",CV_WINDOW_AUTOSIZE);
        //cvNamedWindow(win2,CV_WINDOW_AUTOSIZE);
        frame = cvQueryFrame(capture);
		CvVideoWriter* writer = cvCreateVideoWriter("video.avi",CV_FOURCC('M','J','P','G'),30, cvGetSize(frame));
		/*  CvVideoWriter* writer= cvCreateVideoWriter(<filename>,<format>,<fps>,<size>)    */
 
        while(1)
        {
                frame = cvQueryFrame(capture);
                //output = createbinary(frame);
                cvWriteFrame( writer, frame );
 
                cvShowImage("win",frame);
                //cvShowImage(win2,output);
                char c=cvWaitKey(33);
                if(c==27)
                        break;
        }
        //printf("%lld\n",fps);
        cvReleaseCapture(&capture);
        cvReleaseImage(&frame);
        cvReleaseVideoWriter( &writer );
 
        //cvReleaseImage(&output);
        cvDestroyWindow("win");
        //cvDestroyWindow(win2);
        return 0;
}

