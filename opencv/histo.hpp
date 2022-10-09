//
//  histo.hpp
//  opencv
//
//  Created by 정동욱 on 2022/10/07.
//

#ifndef histo_h
#define histo_h
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/types_c.h>

using namespace cv;
using namespace std;

void calc_Histo(const Mat& img, Mat& hist, Vec3i bins, Vec3f range, Mat mask);
void draw_ellipse(Mat& image, Rect2d obj, Scalar color, int thickness, double ratio);
void make_masks(vector<Rect> sub_obj, Size org_size, Mat mask[4]);
void calc_histos(Mat correct_img, vector<Rect> sub_obj, Mat hists[4], Mat masks[4]);

#endif /* histo_h */
