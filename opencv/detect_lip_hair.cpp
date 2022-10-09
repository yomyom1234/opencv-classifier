//
//  detect_lip_hair.cpp
//  opencv
//
//  Created by 정동욱 on 2022/10/07.
//

#include "detect_area.hpp"

//입술영역 계산 방식
Rect detect_lip(Point2d face_center, Rect face)
{
    //입술 중심 = 대충 얼굴 중심에서 얼굴 높이의 30% 위치
    Point2d lip_center = face_center + Point2d(0, face.height * 0.30);
    //입술 크기 = 얼굴 높이 10%, 너비 18%
    Point2d gap_size(face.width * 0.18, face.height * 0.1);
    
    //입술 시작 좌표
    Point lip_start = lip_center - gap_size;
    //입술 종료 좌표
    Point lip_end = lip_center + gap_size;
    
    //입술 네모를 리턴
    return (Rect(lip_start, lip_end));
}

//윗머리와 귀 밑머리 검출
void detect_hair(Point2d face_center, Rect face, vector<Rect> &hair_rect)
{
    //전체 머리 영역 = 얼굴영역의 가로 90%, 세로 130%
    Point2d h_gap(face.width * 0.45, face.height * 0.65);
    //머리 시작부분
    Point2d pt1 = face_center - h_gap;
    //머리 끝부분
    Point2d pt2 = face_center + h_gap;
    Rect hair(pt1, pt2);
    
    //전체 머리영역 중 윗머리는 상단의 40%, 밑머리는 하단의 40%로 설정
    Size size(hair.width, hair.height * 0.40);
    //윗머리
    Rect hair1(hair.tl(), size);
    //밑머리
    Rect hair2(hair.br() - (Point)size, size);
    
    hair_rect.push_back(hair1);
    hair_rect.push_back(hair2);
    hair_rect.push_back(hair);

}
