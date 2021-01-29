#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

//Mat Mat::operator()(const Rect& roi) const;
//Mat Mat::operator()(Range rowRange, Range colRange) const;
/*
Mat Mat::rowRange(int startrow, int endrow) const;
Mat Mat::rowRange(const Range& r) const;

Mat Mat::colRange(int startcol, int endcol) const;
Mat Mat::colRange(const Range& r) const;

Mat Mat::row(int y) const;
Mat Mat::col(int x) const;
*/
int main() {
	Mat img1 = imread("cat.bmp");
	Mat img2 = img1(Rect(220, 120, 340, 240)); // 얕은 복사
	Mat img3 = img1(Rect(220, 120, 340, 240)).clone(); // 깊은 복사

	img2 = ~img2; // 반전 (얕은 복사이므로 img1도 반전)
	
	imshow("img1", img1); // 반전된 이미지
	imshow("img2", img2); // 반전된 이미지
	imshow("img3", img3); // 원본에서 복사된 이미지

	waitKey();
	destroyAllWindows();
	return 0;
}