#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

/*
template<typename _Tp> class Point_ {
public:
Point_();
Point_(_Tp _x_, _Tp _y);
Point_(const Point_& pt);

Point_& operator=(const Point_& pt);

_Tp dot(const Point_& pt) const;
double ddot(const Point_& pt) const;
double cross(const Point_& pt) const;
bool inside(const Rect_<_Tp>& r) const;
...

_Tp x, y;
};

typedef Point_<int>    Point2i;
typedef Point_<int64>  Point2l;
typedef Point_<float>  Point2f;
typedef Point_<double> Point2d;
typedef Point2i        Point;
*/
int main() {
	// 1. 생성자
	Point pt1;             
	cout << pt1 << endl;   // 0, 0

	pt1.x = 5; pt1.y = 10;
	cout << pt1 << endl;   // 5, 10
	
	Point pt2(10, 30);     
	cout << pt2 << endl;   // 10, 30
	
	// 2. 연산자 오버로딩
	Point pt1;
	pt1.x = 5; pt1.y = 10; // 5, 10
	Point pt2(10, 30);     // 10, 30

	Point pt3 = pt1 + pt2;
	cout << pt3 << endl;   // 15, 40

	Point pt4 = pt1 * 2;   
	cout << pt4 << endl;   // 10, 20
	
	int d1 = pt1.dot(pt2);
	cout << d1 << endl;    // 5*10 + 10*30 = 50 + 300 = 350

	bool b1 = (pt1 == pt2);
	cout << b1 << endl;    // false

	return 0;
}
