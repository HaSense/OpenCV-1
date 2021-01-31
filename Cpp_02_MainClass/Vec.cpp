#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

/*
template<typename _Tp, int m, int n>
class Matx {
public:
	...
	_Tp val[m*n]; // matrix elements
};

template<typename _Tp, int cn>
class Vec : public Matx<_Tp, cn, 1> {
public:
	...
	_Tp& operator[](int i); // element access
};

template<typename _Tp, int n> static inline
std::ostream& operator<<(std::ostream& out, const Vec<_Tp, n>& vec);
*/

/*
typedef Vec<uchar, 2> Vec2b;
typedef Vec<uchar, 3> Vec3b;
typedef Vec<uchar, 4> Vec4b;

typedef Vec<short, 2> Vec2s;
typedef Vec<short, 3> Vec3s;
typedef Vec<short, 4> Vec4s;

typedef Vec<ushort, 2> Vec2w;
typedef Vec<ushort, 3> Vec3w;
typedef Vec<ushort, 4> Vec4w;

typedef Vec<int, 2> Vec2i;
typedef Vec<int, 3> Vec3i;
typedef Vec<int, 4> Vec4i;
typedef Vec<int, 6> Vec6i;
typedef Vec<int, 8> Vec8i;

typedef Vec<float, 2> Vec2f;
typedef Vec<float, 3> Vec3f;
typedef Vec<float, 4> Vec4f;
typedef Vec<float, 6> Vec6f;

typedef Vec<double, 2> Vec2d;
typedef Vec<double, 3> Vec3d;
typedef Vec<double, 4> Vec4d;
typedef Vec<double, 6> Vec6d;
*/

/*
template<typename _Tp, int cn> inline
_Tp& Vec<_Tp, cn>::operator cv::Matx<T2, m, n>[](int i) {
	// 디버그 모드에서만 동작하는 예외 처리 코드
	// 릴리즈 모드에서는 성능을 고려해 무시됨
	CV_DbgAssert((unsigned)i < (unsigned)cn);
	return this->val[i];
}
*/


int main() {
	Vec3b p1, p2(0, 0, 255); //Vec<uchar, 3> - 컬러영상 픽셀값
	// p2는 uchar val[3] 형식의 매개변수에서
	// val[0] = 0, val[1] = 0, val[2] = 255가 됨

	// 만약 p1 변수의 첫번재 원소를 100으로 하고 싶다면
	p1.val[0] = 100;

	// 연산자 재정의 이용
	p1[0] = 100;

	cout << "p1: " << p1 << endl;
	cout << "p2: " << p2 << endl;

	return 0;
}