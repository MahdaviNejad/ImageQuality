#pragma once

using namespace System;
using namespace System::Collections::Generic;
using namespace std;
using namespace cv;

#include "ColorInfo.h"

namespace ImageQuality {

	public ref class ColorMeasure
	{
	public:
		ColorInfo^ GetColorInfo(cli::array<byte>^ buffer);

	private:
		Mat ReadImage(cli::array<byte>^ buffer);
	};
}