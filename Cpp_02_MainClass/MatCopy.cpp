#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

//Mat Mat::clone() const;
//void Mat::copyTo(OutputArray m) const;
//void Mat::copyTo(OutputArray m, InputArray mask) const;

int main() {
	Mat img1 = imread("dog.bmp");

	Mat img2 = img1; // 복사 생성자 (얕은 복사)
	Mat img3;
	img3 = img1;     // 대입 연산자 (얕은 복사)

	Mat img4 = img1.clone(); // 깊은 복사
	Mat img5;
	img1.copyTo(img5);       // 깊은 복사

	// 얕은 복사, 깊은 복사 확인
	img1.setTo(Scalar(0, 255, 255)); // yellow

	imshow("img1", img1);
	imshow("img2", img2);
	imshow("img3", img3);
	imshow("img4", img4);
	imshow("img5", img5);

	waitKey();
	destroyAllWindows();
	return 0;
}