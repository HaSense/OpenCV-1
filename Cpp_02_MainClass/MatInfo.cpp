#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

//static inline std::ostream& operator<<(std::ostream& out, const Mat& mtx);

int main() {
	Mat img1 = imread("lenna.bmp");

	// cols와 rows 멤버변수를 이용하여 크기 출력
	cout << "width: " << img1.cols << endl;
	cout << "height: " << img1.rows << endl;

	if (img1.type() == CV_8UC1)
		cout << "img1 is a grayscale image." << endl;
	else if (img1.type() == CV_8UC3)
		cout << "img1 is a truecolor image." << endl;

	float data[] = { 2.f, 1.414f, 3.f, 1.732f };
	Mat mat1(2, 2, CV_32FC1, data);

	cout << mat1 << endl;

	return 0;
}