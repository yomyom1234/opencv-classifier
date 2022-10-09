//
//  correct_face.hpp
//  opencv
//
//  Created by 정동욱 on 2022/10/07.
//

#ifndef correct_face_hpp
#define correct_face_hpp
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

Mat calc_rotMap(Point2d face_center, vector<Point2f> pt);
Mat correct_image(Mat image, Mat rot_mat, vector<Point2f>& eyes_center);

#endif /* correct_face_hpp */
