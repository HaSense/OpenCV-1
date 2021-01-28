#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

/*
template<typename _Tp> class Rect_ {
public:
	Rect_();
	Rect_(_Tp _x, _Tp _y, _Tp _width, _Tp _height);
	Rect_(const Rect_& r);
	Rect_(const Point_<_Tp>& org, const Size_<_Tp>& sz);
	Rect_(const Point_<_Tp>& pt1, const Point_<_Tp>& pt2);

	Rect_& operator=(const Rect& r);

	Point_<_Tp> tl() const;
	Point_<_Tp> br() const;
	Size_<_Tp> size() const;
	_Tp area() const;
	bool empty() const;
	bool contains(const Point_<_Tp>& pt) const;

	_Tp x, y, width, height;
};

typedef Rect_<int>    Rect2i;
typedef Rect_<float>  Rect2f;
typedef Rect_<double> Rect2d;
typedef Rect2i        Rect;
*/

int main() {
	// 생성자 사용
	Rect rc1;
	Rect rc2(10, 10, 60, 40);

	cout << rc1 << endl;          // [0 x 0 from (0, 0)]
	cout << rc2 << endl;          // [60 x 40 from (10, 10)]
	cout << rc2.br() << endl;     // (10+60, 10+40) = (70, 50)

	// 연산자 오버로딩 사용
	Rect rc3 = rc1 + Size(50, 40);
	cout << rc3 << endl;          // [(0+50) x (0+40) from (0, 0)] = [50 x 40 from (0, 0)]

	Rect rc4 = rc2 + Point(10, 10);
	cout << rc4 << endl;          // [60 x 40 from (10+10, 10+10)] = [60 x 40 from (20, 20)]

	// 연산자 오버로딩 - 논리 연산 수행
	// & 연산: 두 사각형이 교차하는 사각형 영역 반환
	Rect rc5 = rc3 & rc4;
	cout << rc5 << endl;          // [30 x 20 from (20, 20)]

	// | 연산: 두 사각형을 모두 포함하는 최소 크기의 사각형 반환
	Rect rc6 = rc3 | rc4;
	cout << rc6 << endl;          // [80 x 60 from (0, 0)]

	return 0;
}