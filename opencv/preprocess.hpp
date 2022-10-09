//
//  preprocess.hpp
//  opencv
//
//  Created by 정동욱 on 2022/10/06.
//

#ifndef preprocess_h
#define preprocess_h
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

void load_cascade(CascadeClassifier& cascade, string fname);
Mat preprocessing(Mat image);
Point2d calc_center(Rect obj);

#endif /* preprocess_h */
