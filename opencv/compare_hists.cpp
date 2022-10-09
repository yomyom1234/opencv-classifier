//
//  compare_hists.cpp
//  opencv
//
//  Created by 정동욱 on 2022/10/07.
//
#include "histo.hpp"

//히스토그램 계산 함수
void calc_Histo(const Mat& img, Mat& hist, Vec3i bins, Vec3f range, Mat mask)
{
    int dims = img.channels();
    int channels[] = {0, 1, 2};
    int histSize[] = {bins[0], bins[1], bins[2]};
    
    float range1[] = {0, range[0]};
    float range2[] = {0, range[1]};
    float range3[] = {0, range[2]};
    const float* ranges[] = {range1, range2, range3};
    
    calcHist(&img, 1, channels, mask, hist, dims, histSize, ranges);
}

//타원 만드는 함수
void draw_ellipse(Mat& image, Rect2d obj, Scalar color, int thickness, double ratio)
{
    Point2d center = obj.tl() + (Point2d)obj.size() * 0.5;
    Size2d size = (Size2d)obj.size() * ratio;
    ellipse(image, center, size, 0, 0, 360, color, thickness);
}

//계산 더 편하게 하기 위해, 여러 부분으로 나눠서 계산하려고 함. 마스크 만드는 함수
void make_masks(vector<Rect> sub_obj, Size org_size, Mat mask[4])
{
    Mat base_mask(org_size, CV_8U, Scalar(0));
    draw_ellipse(base_mask, sub_obj[2], Scalar(255), -1, 0.45f);
    
    mask[0] = ~base_mask(sub_obj[0]);
    mask[1] = ~base_mask(sub_obj[1]);
    
    draw_ellipse(base_mask, sub_obj[3], Scalar(0), -1, 0.45f);
    mask[3] = ~base_mask(sub_obj[3]);
    mask[2] = base_mask(sub_obj[2]);
}

//히스토그램들 계산 함수
void calc_histos(Mat correct_img, vector<Rect> sub_obj, Mat hists[4], Mat masks[4])
{
    Vec3i bins(64, 64, 64);
    Vec3f ranges(256, 256, 256);
    
    for (int i = 0; i < (int)sub_obj.size(); i++)
    {
        Mat sub = correct_img(sub_obj[i]);
        calc_Histo(sub, hists[i], bins, ranges, masks[i]);
    }
}
