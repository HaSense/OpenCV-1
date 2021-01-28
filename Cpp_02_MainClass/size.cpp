#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

/*
template<typename _Tp> class Size_ {
public:
	Size_();
	Size_(_Tp _width, _Tp _height);
	Size_(const Size_& sz);

	Size_& operator=(const Size_& sz);

	_Tp area() const;
	bool empty() const;

	_Tp width, height;
};

typedef Size_<int>    Size2i;
typedef Size_<int64>  Size2l;
typedef Size_<float>  Size2f;
typedef Size_<double> Size2d;
typedef Size2i        Size;
*/

int main() {
	// 생성자와 멤버 변수 사용
	Size sz1, sz2(10, 20);
	cout << sz1 << endl;             // [0 x 0]
	cout << sz2 << endl;			 // [10 x 20]

	sz1.width = 5; sz1.height = 10;
	cout << sz1 << endl;             // [5 x 10]

	// 연산자 오버로딩
	Size sz3 = sz1 + sz2;
	cout << sz3 << endl;             // [10+5 x 20+10] = [15 x 30]

	Size sz4 = sz1 * 2;
	cout << sz4 << endl;             // [5*2 x 10*2] = [10 x 20]

	int area1 = sz4.area();
	cout << area1 << endl;           // 10*20 = 200

	return 0;
}