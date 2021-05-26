#include "opencv2/highgui/highgui.hpp"

int main( int argc, char** argv )
{
    IplImage* img = cvLoadImage("../images/image.png");
    cvNamedWindow("Example1", CV_WINDOW_AUTOSIZE);
    cvShowImage("Example1", img);
    cvWaitKey(0);
    cvReleaseImage(&img);
    cvDestroyWindow("Example1");
}