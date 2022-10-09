//
//  correct_face.cpp
//  opencv
//
//  Created by 정동욱 on 2022/10/07.
//
#include "correct_angle.hpp"

//두 눈 높이의 각도 차이를 계산해서, 회전 변환 행렬을 리턴하는 함수
Mat calc_rotMap(Point2d face_center, vector<Point2f> pt)
{
    //왼쪽이 높은지, 오른쪽이 높은지 체크
    Point2d delta = (pt[0].x > pt[1].x) ? pt[0] - pt[1] : pt[1] - pt[0];
    double angle = fastAtan2(delta.y, delta.x);
    
    Mat rot_mat = getRotationMatrix2D(face_center, angle, 1);
    return (rot_mat);
}

//회전 변환 행렬을 바탕으로 이미지를 회전시키는 함수
Mat correct_image(Mat image, Mat rot_mat, vector<Point2f>& eyes_center)
{
    Mat correct_img;
    warpAffine(image, correct_img, rot_mat, image.size(), INTER_CUBIC);
    
    for (int i= 0; i < eyes_center.size(); i++)
    {
        Point3d coord(eyes_center[i].x, eyes_center[i].y, 1);
        Mat dst = rot_mat * (Mat)coord;
        eyes_center[i] = (Point2f)dst;
    }
    return (correct_img);
}
