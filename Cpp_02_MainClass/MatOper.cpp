#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

/*
MatExpr operator+(const Mat& a, const Mat& b);
MatExpr operator+(const Mat& a, const Scalar& s);
MatExpr operator+(const Scalar& s, const Mat& a);

MatExpr operator-(const Mat& a, const Mat& b);
MatExpr operator-(const Mat& a, const Scalar& s);
MatExpr operator-(const Scalar& s, const Mat& a);
MatExpr operator-(const Mat& m);

MatExpr operator*(const Mat& a, const Mat& b);
MatExpr operator*(const Mat& a, const double s);
MatExpr operator*(const double s, const Mat& a);

MatExpr operator/(const Mat& a, const Mat& b);
MatExpr operator/(const Mat& a, const double s);
MatExpr operator/(const double s, const Mat& a);
*/

//MatExpr Mat::mul(InputArray m, double scale = 1) const;
//MatExpr Mat::inv(int method = DECOMP_LU) const;
//MatExpr Mat::t() const;

int main() {
	float data[] = { 1, 1, 2, 3 };
	Mat mat1(2, 2, CV_32FC1, data);
	cout << "mat1:\n" << mat1 << endl;

	Mat mat2 = mat1.inv(); // 역행렬
	cout << "mat2:\n" << mat2 << endl;

	cout << "mat1.t():\n" << mat1.t() << endl; // 전치행렬
	cout << "mat1 + 3:\n" << mat1 + 3 << endl; // 행렬의 스칼라 합
	cout << "mat1 + mat2:\n" << mat1 + mat2 << endl; // 행렬끼리의 합
	cout << "mat1 * mat2:\n" << mat1 * mat2 << endl; // 행렬의 원소끼리 곱(multiplication)

	return 0;
}