#include <iostream>
#include <string>

// OpenCV properties
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"

using namespace std;
using namespace cv;

int KERNEL_LENGTH = 3;
// input image
Mat src;
// output result of mean(Homogeneous) filter, Gaussian filter, Median filter, and Bilateral filter, respectively
Mat dstMean;
Mat dstGaussian;
Mat dstMedian;
Mat dstBilateral;

int main(int argc, char ** argv)
{
	// input image
	//const char *inputfile = argc >= 2 ? argv[1] : "miat.bmp";
	string inputfile(argc >= 2 ? argv[1] : "miat.bmp");
	
	// output image
	//const char *outputfile = argc >= 2 ? argv[2] : "result.bmp";
	
	// read input image 
	src = imread(inputfile, CV_LOAD_IMAGE_UNCHANGED);
	//src = imread(inputfile, CV_LOAD_IMAGE_GRAYSCALE);
	if(src.empty())
	{
		cout << "Error opening image " << inputfile << endl;
		return -1;
	}

	namedWindow("Original image", WINDOW_AUTOSIZE);
	imshow("Original image", src);
	waitKey(0);
	
	// mean(Homogeneous) filter
	blur(src, dstMean, Size(KERNEL_LENGTH, KERNEL_LENGTH));
	namedWindow("mean filter", WINDOW_AUTOSIZE);
	imshow("mean filter", dstMean);
	waitKey(0);

	// Gaussian filter
	GaussianBlur(src, dstGaussian, Size(KERNEL_LENGTH, KERNEL_LENGTH), 0, 0);
	namedWindow("Gaussian filter", WINDOW_AUTOSIZE);
	imshow("Gaussian filter", dstGaussian);
	waitKey(0);
	
	// Median filter
	medianBlur(src, dstMedian, KERNEL_LENGTH);
	namedWindow("median filter", WINDOW_AUTOSIZE);
	imshow("median filter", dstMedian);
	waitKey(0);
	
	// Bilateral filter
	bilateralFilter(src, dstBilateral, KERNEL_LENGTH, KERNEL_LENGTH * 2, KERNEL_LENGTH / 2);
	namedWindow("bilateral filter", WINDOW_AUTOSIZE);
	imshow("bilateral filter", dstBilateral);
	waitKey(0);
	
	return 0;
}
