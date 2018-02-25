#include <iostream>

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
Mat dstGausssian;
Mat dstMedian;
Mat dstBilateral;

int main(int argc, char ** argv)
{
	// input image
	const char *inputfile = argc >= 2 ? argv[1] : "miat.bmp";
	
	// output image
	//const char *outputfile = argc >= 2 ? argv[2] : "result.bmp";
	
	// show input image 
	src = imread(inputfile, CV_LOAD_IMAGE_UNCHANGED);
	//src = imread(inputfile, CV_LOAD_IMAGE_GRAYSCALE);
	imshow(src);
	waitKey(0);
	
	// mean(Homogeneous) filter
	
	// Gaussian filter
	
	// Median filter
	
	// Bilateral filter
	
	return 0;
}