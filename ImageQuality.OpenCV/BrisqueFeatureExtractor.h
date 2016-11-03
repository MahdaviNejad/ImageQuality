#pragma once

#include <fstream>
#include <vector>
#include <iostream>
#include <iomanip>

using namespace System;
using namespace System::Collections::Generic;
using namespace std;
using namespace cv;

namespace ImageQuality {

public ref class BrisqueFeatureExtractor
{
public:
	IList<double>^ BrisqueFeatures(cli::array<byte>^ buffer);

private:
	vector<double> brisquefeatures(Mat image);
	void brisque_feature(Mat imdist, vector<double> &feat);
	void estimateggdparam(Mat vec, double &gamparam, double &sigma);
	void estimateaggdparam(Mat vec, double &alpha, double &leftstd, double &rightstd);
	void brisque_process(Mat imdist, vector<double> &feat);
	Mat circshift(Mat structdis, int a, int b);
	double Gamma(double x);
};

}