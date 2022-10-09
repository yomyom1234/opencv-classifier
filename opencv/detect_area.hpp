//
//  detect_lip_hair.hpp
//  opencv
//
//  Created by 정동욱 on 2022/10/07.
//

#ifndef detect_lip_hair_hpp
#define detect_lip_hair_hpp
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

Rect detect_lip(Point2d face_center, Rect face);
void detect_hair(Point2d face_center, Rect face, vector<Rect> &hair_rect);

#endif /* detect_lip_hair_hpp */
