#include "BaseColor.h"
#include <iostream>



BaseColor::BaseColor() : m_Red(-1), m_Green(-1), m_Blue(-1)
{
}

BaseColor::BaseColor(int red, int green, int blue) : m_Red(red) , m_Green(green), m_Blue(blue)
{
}

BaseColor::BaseColor(const BaseColor & color) : m_Red(color.m_Red), m_Green(color.m_Green), m_Blue(color.m_Blue)
{
	
}

BaseColor & BaseColor::operator=(const BaseColor & color)
{
	if (this != &color)
	{
		m_Red = color.m_Red;
		m_Green = color.m_Green;
		m_Blue = color.m_Blue;
	}
	
	return *this;
}

bool BaseColor::operator==(const BaseColor & color)
{
	if(m_Red == color.m_Red && m_Green == color.m_Green && m_Blue == color.m_Blue)
		return true;
	return false;
}

std::ostream & operator<<(std::ostream & out, const BaseColor & color)
{
	out << "Red Value : [" << color.m_Red << "], Green Value : [" << color.m_Green << "], Blue Value : [" << color.m_Blue<<"]" << std::endl;
	return out;
}


BaseColor::~BaseColor()
{
}

