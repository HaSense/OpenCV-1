#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

/*
class RotatedRect {
public:
	RotatedRect();
	RotatedRect(const Point2f& _center, const Size2f& _size, float _angle);
	RotatedRect(const Point2f& point1, const Point2f& point2, const Point2f& point3);

	void points(Point2f pts[]) const;
	Rect boundingRect() const;
	Rect_<float> boundingRect2f() const;

	Point2f center;
	Size2f size;
	float angle;
};
*/

int main() {
	// 중심 좌표가 (40, 30), 크기는 40*20, 
	// 시계 방향으로 30도 만큼 회전된 사각형 객체 표현 
	RotatedRect rr1(Point2f(40, 30), Size2f(40, 20), 30.f);

	// 회전된 사각형 객체의 꼭지점 좌표 전체를 알려고 함
	Point2f pts[4];
	rr1.points(pts); // pts는 Point2f[]형이므로 Point2f*형과 같음
	for (int i = 0; i < 4; i++) {
		cout << "pts[" << i << "] = " << pts[i] << endl;
	}

	return 0;
}