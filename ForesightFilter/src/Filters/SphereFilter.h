#pragma once
#include <iostream>
#include "..\Shapes\BaseShape.h"
#include "..\Colors\BaseColor.h"
#include "..\Shapes\Sphere.h"
#include "BaseFilter.h"
#include "opencv2\imgproc.hpp"
#include "..\Colors\TwoWaysColor.h"

class SphereFilter : public BaseFilter<Sphere, TwoWaysColor>
{
public:
	SphereFilter() {};
	~SphereFilter() {};
	bool FilterShape(Sphere * i_ShapeToFilter, TwoWaysColor * io_Color, const std::string & ImagePath) override;
};

