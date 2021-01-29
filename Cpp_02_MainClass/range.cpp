#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

/*
class Range {
public:
	Range();
	Range(int _start, int _end);

	int size() const;
	bool empty() const;
	static Range all();

	int start, end;
};
*/

int main() {
	Range r1(0, 10);
	cout << r1 << endl;

	return 0;
}