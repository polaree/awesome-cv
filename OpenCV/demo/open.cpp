#include "opencv2/highgui/highgui.hpp"
#include "iostream"

// 命名空间
using namespace cv;
using namespace std;

// 函数声明
void openImage();
void openCamera();

// 主函数
int main( int argc, char** argv )
{
    String type = argv[1];
    cout << "Received Command " << type << endl;

    if (type == "image"){
        openImage();
        cout << "Need Open Image";
    } else if (type == "camera") {
        openCamera();
        cout << "Need Open Camera";
    }
}

// 子函数
void openImage() {
    IplImage* img = cvLoadImage("../images/image.png");
    cvNamedWindow("Example1", CV_WINDOW_AUTOSIZE);
    cvShowImage("Example1", img);
    cvWaitKey(0);
    cvReleaseImage(&img);
    cvDestroyWindow("Example1");
}

void openCamera() {
    VideoCapture cap(0);
    Mat frame;
    
    while(true){
        cap >> frame;
        if (frame.empty())
            break;
        imshow("Camera", frame);
        if (waitKey(1)==27){
            break;
        }
        
    }
    cap.release();
}