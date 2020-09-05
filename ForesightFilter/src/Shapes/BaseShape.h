#pragma once
#include <string>

struct Location
{
	float m_X{ 0 };
	float m_Y{ 0 };
	float m_Z{ 0 };

	bool operator==(const Location& loc)
	{
		if((m_X == loc.m_X) && (m_Y == loc.m_Y) && (m_Z == loc.m_Z))
			return true;
		return false;			
	}
};

class BaseShape
{
public:
	
	BaseShape();
	BaseShape(std::string type, Location location);
	BaseShape(const BaseShape& shape);
	BaseShape& operator=(const BaseShape& shape);
	bool operator==(const BaseShape& shape);
	~BaseShape();


	virtual std::string GetShapeName() const { return m_shapeType; }
	virtual void SetShapeName(std::string val) { m_shapeType = val; }
	
	virtual Location GetShapeLocation() const { return m_Location; }
	virtual void SetShapeLocation(Location val) { m_Location = val; }
protected:
	

	std::string m_shapeType {""};
	Location m_Location;

	
};

