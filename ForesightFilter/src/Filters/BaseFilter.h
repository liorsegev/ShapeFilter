#pragma once
#include <string>
#include "..\Shapes\BaseShape.h"

template <typename DerivedShape, typename DerivedColor>
class BaseFilter
{
public:
	
	virtual bool FilterShape(DerivedShape * i_ShapeToFilter, DerivedColor * io_Color, const std::string & ImagePath) = 0;


};

