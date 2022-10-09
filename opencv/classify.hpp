//
//  genderClassifier.hpp
//  opencv
//
//  Created by 정동욱 on 2022/10/07.
//

#ifndef genderClassifier_hpp
#define genderClassifier_hpp

#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/types_c.h>

using namespace cv;
using namespace std;

void display(Mat &image, Point2d face_center, vector<Point2f> eyes_center, vector<Rect> sub);
void classify(Mat& image, Mat hists[4]);

#endif /* genderClassifier_hpp */
