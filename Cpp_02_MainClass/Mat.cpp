#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

/*
class Mat {
public:
	Mat();
	Mat(int rows, int cols, int type);
	Mat(Size size, int type);
	Mat(int rows, int cols, int type, const Scalar& s);
	Mat(Size size, int type, const Scalar& s);
	Mat(const Mat& m);
	~Mat();

	void create(int rows, int cols, int type);
	bool empty() const;

	Mat clone() const;
	void copyTo(OutputArray m) const;
	Mat& setTo(InputArray value, InputArray mask = noArray());

	static MatExpr zeros(int rows, int cols, int type);
	static MatExpr ones(int rows, int cols, int type);

	Mat& operator=(const Mat& m);
	Mat operator()(const Rect& roi) const;

	template<typename _Tp> _Tp* ptr(int i0 = 0);
	template<typename _Tp> _Tp& at(int row, int col);

	int dims;
	int rows, cols;
	uchar* data;
	MatSize size;
	...
};
*/

/*
#define CV_8U   0  //  8bit  Unsigned -> unsigned char     (uchar)
#define CV_8S   1  //  8bit  Signed   ->          char     (schar)
#define CV_16U  2  // 16bit  Unsigned -> unsigned short    (ushort)
#define CV_16S  3  // 16bit  Signed   ->          short
#define CV_32S  4  // 32bit  Signed   ->          int
#define CV_32F  5  // 32bit  Float    ->          float
#define CV_64F  6  // 64bit  Float    ->          double
#define CV_16F  7  // 16bit  Float    ->          float16_t
*/

/*
typedef signed char schar;
typedef unsigned char uchar;
// short (C/C++ 기본 자료형) (2byte)
typedef unsigned short ushort;
// int (C/C++ 기본 자료형) (4byte)
typedef unsigned uint;
typedef __int64 int64;
typedef unsigned __int64 uint64;
// float (C/C++ 기본 자료형) (4byte)
class float16_t   // signed float (2byte)
				  // double (C/C++ 기본 자료형) (8byte)
*/

//Mat::Mat(int rows, int cols, int type);
//Mat::Mat(Size size, int type);
//Mat::Mat(int rows, int cols, int type, const Scalar& s);
//Mat::Mat(Size size, int type, const Scalar& s);

//static MatExpr Mat::zeros(int rows, int cols, int type);
//static MatExpr Mat::zeros(Size size, int type);
//static MatExpr Mat::ones(int rows, int cols, int type);
//static MatExpr Mat::ones(Size size, int type);
//static MatExpr Mat::eye(int rows, int cols, int type);
//static MatExpr Mat::eye(Size size, int type);

//Mat::Mat(int rows, int cols, int type, void* data, size_t step = AUTO_STEP);
//Mat::Mat(Size size, int type, void* data, size_t step = AUTO_STEP);

//void Mat::create(int rows, int cols, int type);
//void Mat::create(Size size, int type);

//Mat& Mat::operator=(const Scalar& s);
//Mat& Mat::setTo(InputArray value, InputArray mask = noArray());

// 3차원 이상의 다차원 행렬에 대한 생성자
//Mat::Mat(int ndims, const int* sizes, int type);
//Mat::Mat(const std::vector<int>& sizes, int type);

int main() {
	// 기본 생성자
	Mat img1;

	// 생성과 동시에 원소 값 저장을 위한 메모리 공간 할당
	Mat img2(480, 640, CV_8UC1); // unsigned char, 1-channel
	Mat img3(480, 640, CV_8UC3); // unsigned char, 3-channels (방금 전 코드)
	
	// Size 클래스 이용
	Mat img4(Size(640, 480), CV_8UC3); // unsigned char, 3-channels

	// Scalar 클래스 이용 - 원소 초기값
	// 모든 픽셀 값이 128로 초기화된 그레이스케일 영상
	Mat img5(480, 640, CV_8UC1, Scalar(128));       // initial value 128
	// 모든 픽셀이 빨간색으로 설정된 컬러 영상
	Mat img6(480, 640, CV_8UC3, Scalar(0, 0, 255)); // initial value Red

	// 0으로 초기화된 행렬
	Mat mat1 = Mat::zeros(3, 3, CV_32SC1); // 0's matrix

	// 1로 초기화된 행렬과 단위 행렬
	Mat mat2 = Mat::ones(3, 3, CV_32FC1); // 1's matrix
	Mat mat3 = Mat::eye(3, 3, CV_32FC1);  // identity matrix

	// 외부 데이터로 초기화
	float data[] = { 1, 2, 3, 4, 5, 6 }; // float 6개
	Mat mat4(2, 3, CV_32FC1, data);      // 2*3 = 6개, 32bit float channel 1
	cout << mat4 << endl;

	// Mat_ 클래스 사용
	Mat_<float> mat5_(2, 3);
	mat5_ << 1, 2, 3, 4, 5, 6; // << 연산자와 콤마(,) 연산자를 이용한 원소 값 설정
	Mat mat5 = mat5_;          // Mat 클래스와 상호 변환 가능
	cout << mat5 << endl;

	// mat5_를 사용하지 않고 바로 정의
	Mat mat6 = (Mat_<float>(2, 3) << 1, 2, 3, 4, 5, 6);
	cout << mat6 << endl;

	// 초기화 리스트 사용
	Mat mat7 = Mat_<float>({ 2, 3 }, { 1, 2, 3, 4, 5, 6 });
	cout << mat7 << endl;

	// create 함수
	// 기존 행렬 (앞서 쓴 코드)
	//Mat mat4(2, 3, CV_32FC1, data);      // 2*3, float, 1-channel
	//Mat mat7 = Mat_<float>({ 2, 3 }, { 1, 2, 3, 4, 5, 6 }); // 2x3, float, 1-channel

	mat4.create(256, 256, CV_8UC3);      // 256x256 uchar, 3-channels
	mat7.create(4, 4, CV_32FC1);         // 4x4, float, 1-channel

	// 대입 연산자 오버로딩과 setTo를 이용해 create 이후 초기화
	mat4 = Scalar(255, 0, 0); // Blue로 설정함 (BGR)
	mat7.setTo(1.f);          // 1.f로 설정함

	return 0;
}