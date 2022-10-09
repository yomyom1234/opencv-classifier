//
//  genderClassifier.cpp
//  opencv
//
//  Created by 정동욱 on 2022/10/07.
//

#include "classify.hpp"
#include "histo.hpp"

//성별 구분
void classify(Mat& image, Mat hists[4])
{
    //기준 1 = 윗머리와 밑머리의 차이
    double criteria1 = compareHist(hists[0], hists[1], CV_COMP_CORREL);
    //기준 2 = 얼굴 색과 입술 색의 차이
    double criteria2 = compareHist(hists[2], hists[3], CV_COMP_CORREL);
    
    //유사도 비교
    double tmp = (criteria1 > 0.2) ? 0.2 : 0.4;
    int value = (criteria2 > tmp) ? 0 : 1;
    string text = (value) ? "Man" : "Woman";
    
    //성별 글 넣기
    int font = FONT_HERSHEY_TRIPLEX;
    putText(image, text, Point(12, 31), font, 0.7, Scalar(0,0,0), 2);
    putText(image, text, Point(10, 30), font, 0.7, Scalar(0,255,0), 1);
    
    cout << text << format(" - 유사도 [머리 : %4.2f 입술 :  %4.2f]\n", criteria1, criteria2);
}

//얼굴과 입술영역 그림에 표시해주는 함수
void display(Mat &image, Point2d face_center, vector<Point2f> eyes_center, vector<Rect> sub)
{
    circle(image, eyes_center[0], 10, Scalar(0, 255, 0), 2);
    circle(image, eyes_center[1], 10, Scalar(0, 255, 0), 2);
    circle(image, face_center, 3, Scalar(0, 0, 255), 2);
    
    draw_ellipse(image, sub[2], Scalar(255, 100, 0), 2, 0.45f);
    draw_ellipse(image, sub[3], Scalar(0, 0, 255), 2, 0.45f);
}
