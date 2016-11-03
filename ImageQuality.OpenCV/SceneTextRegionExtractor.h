#pragma once

#include "Region.h"
#include "GetRegionsResult.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace std;
using namespace cv;

namespace ImageQuality {

	public ref class SceneTextRegionExtractor
	{
	private:
		const int MinWidth = 20;
		const int MinHeight = 12;

	public:
		GetRegionsResult^ GetRegions(cli::array<byte>^ buffer);
		IList<GetRegionsResult^>^ SimpleWatermark(cli::array<byte>^ buffer);

	private:
		vector<Rect> MergeRects(int width, int height, vector<Rect> rects, int expand);
		bool VerticalHeuristics(Mat roi);
		bool HorizontalHeuristics(Mat roi);
		vector<vector<double>> HeuristicSplit(vector<double> values);
		bool NeedsInverse(Mat roi);
		Nullable<float> FindBestAngle(vector<float> angles);
		GetRegionsResult^ DetectAndRotate(Mat img, Scalar lower, Scalar upper);
		cli::array<byte>^ ToByteArray(Mat image, const string& extension);
		void WriteToStream(const std::string& extension, Mat image, Stream^ stream);
		Mat ReadImage(cli::array<byte>^ buffer);
	};
}