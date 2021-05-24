#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
 
using namespace std;
using namespace cv;

Mat src, dst, src_gray;

char* window_name = "Demo";

/**
 * @主函数
 */
int main( int argc, char** argv )
{

    /// 读取一副图片，不改变图片本身的颜色类型（该读取方式为DOS运行模式）
    src = imread(argv[1], 1 );

    /// 将图片转换成灰度图片
    cvtColor(src, src_gray, CV_RGB2GRAY);

    namedWindow(window_name, CV_WINDOW_AUTOSIZE);

    imshow(window_name, src_gray);

    while(true) {
        int c;
        c = waitKey(20);
        if (27 == (char) c) {
            break;
        }
    }
}