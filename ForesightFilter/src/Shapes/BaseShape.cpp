#include "BaseShape.h"



BaseShape::BaseShape()
{
	m_shapeType = "BaseShape";
}

BaseShape::BaseShape(std::string type, Location location) : m_shapeType(type), m_Location(location)
{
}

BaseShape::BaseShape(const BaseShape & shape) : m_shapeType(shape.m_shapeType), m_Location(shape.m_Location)
{
	
}

BaseShape & BaseShape::operator=(const BaseShape & shape)
{
	if (this != &shape)
	{
		m_shapeType = shape.m_shapeType;
		m_Location = shape.m_Location;
	}	
	return *this;
}

bool BaseShape::operator==(const BaseShape & shape)
{
	if ((m_shapeType == shape.m_shapeType) && (m_Location == shape.m_Location))
		return true;
	return false;
}


BaseShape::~BaseShape()
{
}

