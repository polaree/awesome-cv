#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <vector>
#include <cstdio>
using namespace std;
using namespace cv;

Mat faceTracing(Mat);

int main( int argc, char** argv )
{
    VideoCapture cap(0);
    Mat frame;
    Mat frameDst;
    
    while(true){
        cap >> frame;
        if (frame.empty())
            break;
        frameDst = faceTracing(frame);
        imshow("Camera", frame);
        imshow("Camera", frameDst);
        if (waitKey(1)==27){
            break;
        }
        
    }
    cap.release();
}

Mat faceTracing(Mat srcImage) {
    if (srcImage.empty()){
        cout << "srcImage is empty" << endl;
        return srcImage;
    }
    
// 【1】加载分类器
	CascadeClassifier cascade;
	cascade.load("../data/haarcascade_eye.xml");

	Mat grayImage, dstImage;
	// 【2】读取图片
	dstImage = srcImage.clone();

	cvtColor(srcImage, grayImage, COLOR_BGR2GRAY); // 生成灰度图，提高检测效率
    if (grayImage.empty()){
        cout << "grayImage is empty" << endl;
        return srcImage;
    }


	// 定义7种颜色，用于标记眼睛
	Scalar colors[] =
	{
		// 红橙黄绿青蓝紫
		CV_RGB(255, 0, 0),
		CV_RGB(255, 97, 0),
		CV_RGB(255, 255, 0),
		CV_RGB(0, 255, 0),
		CV_RGB(0, 255, 255),
		CV_RGB(0, 0, 255),
		CV_RGB(160, 32, 240)
	};

	// 【3】检测
	vector<Rect> rect;
	cascade.detectMultiScale(grayImage, rect, 1.1, 3,0);  // 分类器对象调用
	cout << "检测到眼睛个数：" << rect.size() << endl; // 将识别的眼睛的数量显示在控制台中
	// 【4】标记--在眼睛处画圆
	for (int i = 0; i < rect.size(); i++)
	{
		Point  center;
		int radius;
		center.x = cvRound((rect[i].x + rect[i].width * 0.5));
		center.y = cvRound((rect[i].y + rect[i].height * 0.5));
		radius = cvRound((rect[i].width + rect[i].height) * 0.25);
		circle(dstImage, center, radius, colors[i % 7], 2);
    }
	// 【5】返回
	return dstImage;
}