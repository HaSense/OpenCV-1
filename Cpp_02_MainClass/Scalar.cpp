#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

/*
template<typename _Tp> 
class Scalar_ : public Vec<_Tp, 4> {
public:
	Scalar_();
	Scalar_(_Tp v0);
	Scalar_(_Tp v0, _Tp v1, _Tp v2 = 0, _Tp v3 = 0);

	static Scalar_<_Tp> all(_Tp v0);
	...
};

typedef Scalar_<double> Scalar;
*/

int main() {
	Scalar gray = 128;
	cout << "gray: " << gray << endl;

	Scalar yellow(0, 255, 255);
	cout << "yellow: " << yellow << endl;

	Mat img1(256, 256, CV_8UC3, yellow); // 노란색 컬러 영상
	for (int i = 0; i < 4; i++)
		cout << yellow[i] << endl;

	return 0;
}