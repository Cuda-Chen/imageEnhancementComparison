#include <iostream>
#include <string>

// OpenCV properties
#include "opencv2/imgproc.hpp"
#include "opencv2/ximgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"

using namespace std;
using namespace cv;

// kernel length declare here
int KERNEL_LENGTH = 0;
// input image
Mat src;
// output result of mean(Homogeneous) filter, Gaussian filter, Median filter, Bilateral filter, and guided filter, respectively
Mat dstMean;
Mat dstGaussian;
Mat dstMedian;
Mat dstBilateral;
Mat dstGuided;

string getFileName(const string &s)
{
	size_t i = s.rfind(".", s.length());
	if(i != string::npos)
	{
		return (s.substr(0, i));
	}

	return ("");
}

int main(int argc, char ** argv)
{
	// check input param number
	if(argc != 4)
	{
		cout << "Usage: ./imageEnhancementComparison [input image name] [kernel size number] [guided filter image]" << endl;
		return 1;
	}

	// input image
	string inputfile(argv[1]);

	// change kernel length here
	KERNEL_LENGTH = atoi(argv[2]);

	// set guided filter param here
	string guideImage(argv[3]);
	int r = 16;
	double eps = 0.1 * 0.1;
	Mat guide = imread(guideImage, CV_LOAD_IMAGE_UNCHANGED);
	
	// output images' file name
	string outputMean = getFileName(inputfile) + string("_mean_") + to_string(KERNEL_LENGTH) + string(".bmp");
	string outputGaussian = getFileName(inputfile) + string("_Gaussian_") + to_string(KERNEL_LENGTH) + string(".bmp");
	string outputMedian = getFileName(inputfile) + string("_median_") + to_string(KERNEL_LENGTH) + string(".bmp");
	string outputBiateral = getFileName(inputfile) + string("_Biateral_") + to_string(KERNEL_LENGTH) + string(".bmp");
	string outputGuided = getFileName(inputfile) + string("_guided") + string(".bmp");
	
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
	namedWindow(outputMean, WINDOW_AUTOSIZE);
	imshow(outputMean, dstMean);
	imwrite(outputMean, dstMean);
	waitKey(0);

	// Gaussian filter
	GaussianBlur(src, dstGaussian, Size(KERNEL_LENGTH, KERNEL_LENGTH), 0, 0);
	namedWindow(outputGaussian, WINDOW_AUTOSIZE);
	imshow(outputGaussian, dstGaussian);
	imwrite(outputGaussian, dstGaussian);
	waitKey(0);
	
	// Median filter
	medianBlur(src, dstMedian, KERNEL_LENGTH);
	namedWindow(outputMedian, WINDOW_AUTOSIZE);
	imshow(outputMedian, dstMedian);
	imwrite(outputMedian, dstMedian);
	waitKey(0);
	
	// Bilateral filter
	bilateralFilter(src, dstBilateral, KERNEL_LENGTH, KERNEL_LENGTH * 2, KERNEL_LENGTH / 2);
	namedWindow(outputBiateral, WINDOW_AUTOSIZE);
	imshow(outputBiateral, dstBilateral);
	imwrite(outputBiateral, dstBilateral);
	waitKey(0);

	// guided filter
	cv::ximgproc::guidedFilter(guide, src, dstGuided, r, eps);
	namedWindow(outputGuided, WINDOW_AUTOSIZE);
	imshow(outputGuided, dstGuided);
	imwrite(outputGuided, dstGuided);
	waitKey(0);
	
	return 0;
}
