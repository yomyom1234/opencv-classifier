//
//  detect_face.cpp
//  opencv
//
//  Created by 정동욱 on 2022/10/06.
//

#include <stdio.h>
#include <opencv2/opencv.hpp>
#include "preprocess.hpp"

//검출기를 로드하는 함수
void load_cascade(CascadeClassifier& cascade, string fname)
{
    //검출기가 있는 폴더의 위치
    String path = "/opt/homebrew/Cellar/opencv/4.6.0/share/opencv4/haarcascades/";
    String full_name = path + fname;
    
    //검출기를 로드함
    CV_Assert(cascade.load(full_name));
}

//입력된 이미지에 전처리를 수행하여 화질 개선하는 함수
Mat preprocessing(Mat image)
{
    Mat gray;
    cvtColor(image, gray, COLOR_BGR2GRAY);
    equalizeHist(gray, gray);
    
    return (gray);
}

//사각형의 중심을 계산하는 함수
Point2d calc_center(Rect obj)
{
    Point2d c = (Point2d)obj.size() / 2.0;
    Point2d center = (Point2d)obj.tl() + c;
    return (center);
}
