#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/core/types_c.h>

#include <iostream>
#include <chrono>
#include <cassert>

uint64_t Now() {
    auto now  = std::chrono::high_resolution_clock::now();
    auto nano_time_pt = std::chrono::time_point_cast<std::chrono::nanoseconds>(now);
    auto epoch = nano_time_pt.time_since_epoch();
    uint64_t now_nano = std::chrono::duration_cast<std::chrono::nanoseconds>(epoch).count();
    return now_nano;
}

int main() {
	using namespace cv;
	using namespace std;

	Mat img = imread("hello.jpg");
	imshow("img", img);

	cout << "channels: "  << img.channels() << endl;
	cout << "col: " << img.cols << endl;
	cout << "row: " << img.rows << endl;
	cout << "step.p[0]: " << img.step.p[0] << endl;
	cout << "step.p[1]: " << img.step.p[1] << endl;

	auto start = Now();

	for (int i=0; i<1; i++) {
		for (int j=0; j<10; j++) {
			uint32_t b = img.data[i * img.cols + j * 3];
			uint32_t g = img.data[i * img.cols + j * 3 + 1];
			uint32_t r = img.data[i * img.cols + j * 3 + 2];

			uchar* p = img.ptr(i, j);
			uint32_t b1 = *p++;
			uint32_t g1 = *p++;
			uint32_t r1 = *p;

			assert(b == b1 && g == g1 && r == r1);
			// cout << r << " " << g << " " << b << " # " << r1 << " " << g1 << " " << b1 << endl;
		}
	}

	auto end = Now();
	cout << "cost: " << (end - start) / 1000000.0 << " ms" << endl; 

	waitKey(0);
	return 0;
}
