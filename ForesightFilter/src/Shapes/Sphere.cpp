#include "Sphere.h"



Sphere::Sphere()
{
	m_shapeType = "Sphere";
}

Sphere::Sphere(std::string type, Location location, float radius) : BaseShape(type, location) , m_Radius(radius)
{
}

Sphere::Sphere(const Sphere & shape) : BaseShape(shape) , m_Radius(shape.m_Radius)
{
}

Sphere & Sphere::operator=(const Sphere & shape)
{
	if (this != &shape)
	{
		BaseShape::operator=(shape);
		m_Radius = shape.m_Radius;
	}
	return *this;
}

bool Sphere::operator==(const Sphere & shape)
{
	
	if (BaseShape::operator==(shape) && m_Radius == shape.m_Radius)
		return true;
	return false;
}


Sphere::~Sphere()
{
}
