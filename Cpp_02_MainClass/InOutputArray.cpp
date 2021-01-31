#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

//typedef const _InputArray& InputArray;
//Mat _InputArray::getMat(int idx = -1) const;

//typedef const _OutputArray& OutputArray;

// InputArray 클래스를 이용한 사용자 정의 함수
void printMat(InputArray _mat) {
	Mat mat = _mat.getMat();
	cout << mat << endl;
}

int main() {
	// InputArray
	uchar data1[] = { 1, 2, 3, 4, 5, 6 };
	Mat mat1(2, 3, CV_8U, data1);
	printMat(mat1);

	vector<float> vec1 = { 1.2f, 3.4f, -2.1f };
	printMat(vec1);

	return 0;
}