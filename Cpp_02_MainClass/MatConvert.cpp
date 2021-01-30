#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

//void Mat::convertTo(OutputArray m, int rtype, double alpha = 1, double beta = 0) const;
//Mat Mat::reshape(int cn, int rows = 0) const;
//void Mat::resize(size_t sz);
//void Mat::resize(size_t sz, const Scalar& s);
//template<typename _Tp> void Mat::push_back(const _Tp& elem);
//template<typename _Tp> void Mat::push_back(const Mat_<_Tp>& elem);
//template<typename _Tp> void Mat::push_back(const std::vector<_Tp>& elem);
//void Mat::push_back(const Mat& m);
//void Mat::pop_back(size_t nelems = 1);

int main() {
	// lenna 영상을 그레이스케일로 불러옴
	Mat img1 = imread("lenna.bmp", IMREAD_GRAYSCALE); // uchar

	Mat img1f;
	img1.convertTo(img1f, CV_32FC1); // float

	// reshape
	uchar data1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
	Mat mat1(3, 4, CV_8UC1, data1);
	Mat mat2 = mat1.reshape(0, 1);

	cout << "mat1:\n" << mat1 << endl;
	cout << "mat2:\n" << mat2 << endl;

	// push_back
	Mat mat3 = Mat::ones(1, 4, CV_8UC1) * 255;
	mat1.push_back(mat3);
	cout << "mat1:\n" << mat1 << endl;
	
	// resize
	mat1.resize(5, 100);
	cout << "mat1:\n" << mat1 << endl;

	return 0;
}