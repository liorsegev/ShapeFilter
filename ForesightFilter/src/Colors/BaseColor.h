#pragma once
#include <string>
#include <iostream>
#include <iosfwd>
class BaseColor
{
public:

	BaseColor();
	BaseColor(int red, int green, int blue);
	BaseColor(const BaseColor& color);
	BaseColor& operator=(const BaseColor& color);
	bool operator==(const BaseColor& color);
	friend std::ostream & operator << (std::ostream &out, const BaseColor &color);
	~BaseColor();
	
	int GetRed() const { return m_Red; }
	void SetRed(int val) { m_Red = val; }
	int GetGreen() const { return m_Green; }
	void SetGreen(int val) { m_Green = val; }
	int GetBlue() const { return m_Blue; }
	void SetBlue(int val) { m_Blue = val; }
private:
	int m_Red;
	int m_Green;
	int m_Blue;
};

