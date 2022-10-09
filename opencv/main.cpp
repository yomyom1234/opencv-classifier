//
//  main.cpp
//  opencv
//
//  Created by 정동욱 on 2022/10/06.
//
#include <iostream>
#include "preprocess.hpp"
#include "correct_angle.hpp"
#include "detect_area.hpp"
#include "histo.hpp"
#include "classify.hpp"


//main함수
int main()
{
    CascadeClassifier face_cascade, eyes_cascade;
    //정면 얼굴 검출기 로드
    load_cascade(face_cascade, "haarcascade_frontalface_alt2.xml");
    //눈 검출기 로드
    load_cascade(eyes_cascade, "haarcascade_eye.xml");
    
    //얼굴 이미지 가져오기
    Mat image = imread("/Users/yomyom/Desktop/opencv/src/sample.jpg", IMREAD_COLOR);
    
    //이미지 전처리
    Mat gray = preprocessing(image);
    
    vector<Rect> faces, eyes, sub_obj;
    vector<Point2f> eyes_center;
    //얼굴 검출
    face_cascade.detectMultiScale(gray, faces, 1.1, 2, 0, Size(100, 100));
    
    //검출 했을 때 얼굴을 찾았으면
    if (faces.size() > 0)
    {
        //눈도 검출
        eyes_cascade.detectMultiScale(gray(faces[0]), eyes, 1.15, 7, 0, Size(25, 20));
        
        //만약에 눈도 찾으면
        if (eyes.size() == 2)
        {
            // 눈 중심점
            eyes_center.push_back(calc_center(eyes[0] + faces[0].tl()));
            eyes_center.push_back(calc_center(eyes[1] + faces[0].tl()));
            
            //얼굴 중심점
            Point2d face_center = calc_center(faces[0]);
            //얼굴 기울어진 각도 찾기
            Mat rot_mat = calc_rotMap(face_center, eyes_center);
            //찾은 행렬과 곱해서 기울기 보정
            Mat correct_img = correct_image(image, rot_mat, eyes_center);
            
            //머리영역 검출
            detect_hair(face_center, faces[0], sub_obj);
            //입술영역 검출
            sub_obj.push_back(detect_lip(face_center, faces[0]));
            
            //마스크 만들어서 히스토그램으로 계산
            Mat masks[4], hists[4];
            make_masks(sub_obj, correct_img.size(), masks);
            calc_histos(correct_img, sub_obj, hists, masks);
            
            classify(correct_img, hists);
            display(correct_img, face_center, eyes_center, sub_obj);
            imshow("correct_img", correct_img);
            waitKey(0);
        }
    }
    return (0);
}
