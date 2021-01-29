#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

//template<typename _Tp> _Tp& Mat::at(int y, int x);
//template<typename _Tp> _Tp* Mat::ptr(int y);

int main() {
	// Mat::at() 함수로 원소 순회
	Mat mat1 = Mat::zeros(3, 4, CV_8UC1);
	// 8bit unsigned char(uchar) 1-channel

	for (int j = 0; j < mat1.rows; j++) {
		for (int i = 0; i < mat1.cols; i++) {
			mat1.at<uchar>(j, i)++; // 1만큼 증가
		}
	}

	cout << mat1 << endl;

	// Mat::ptr() 함수로 원소 순회
	for (int j = 0; j < mat1.rows; j++) {
		uchar* p = mat1.ptr<uchar>(j);
		for (int i = 0; i < mat1.cols; i++) {
			p[i]++;
		}
	}

	cout << mat1 << endl;

	// MatIterator_ 반복자로 원소 순회
	for (MatIterator_<uchar> it = mat1.begin<uchar>();
		it != mat1.end<uchar>(); ++it) {
		(*it)++; // 반복자 변수가 참조하는 값에 대해 연산함에 주의
	}

	cout << mat1 << endl;

	return 0;
}