#pragma once
#include "BaseShape.h"
class Sphere : public BaseShape
{
public:
	Sphere();
	Sphere(std::string type, Location location,float radius);
	Sphere(const Sphere& shape);
	Sphere& operator=(const Sphere& shape);
	bool operator==(const Sphere& shape);
	~Sphere();

	float GetRadius() const { return m_Radius; }
	void SetRadius(float val) { m_Radius = val; }
private:

	float m_Radius{ 0 };

};

