#include <opencv2/opencv.hpp>
#include <sstream>
#include <iostream>
#include "IrisCenterDetection.h"

using namespace std;
using namespace cv;

void readImg(int number, Mat& img)
{
	std::stringstream strStream;
	std::string filename;
	strStream << number;
	filename = "eye region-highlight/eye" + strStream.str() + ".jpg";
	//filename = "eye region/eye" + strStream.str() + ".jpg";
	img = cv::imread(filename, 0);
	strStream.str("");
}

int main()
{
	Mat img;
	IrisDetection irisDetection;
	int count = 1;
	while (waitKey(0) != 27)
	{
		readImg(count, img);
		if (img.data != nullptr)
		{
			irisDetection.ProcessEye(img);
			imshow("img", img);
		}
		count++;
	}
}