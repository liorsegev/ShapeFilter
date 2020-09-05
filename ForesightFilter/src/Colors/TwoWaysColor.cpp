#include "TwoWaysColor.h"



TwoWaysColor::TwoWaysColor()
{
}

TwoWaysColor::TwoWaysColor(BaseColor inColor, BaseColor outColor) : m_inColor(inColor) , m_outColor(outColor)
{
}

TwoWaysColor::TwoWaysColor(const TwoWaysColor & color) : m_inColor(color.m_inColor), m_outColor(color.m_outColor)
{
}

TwoWaysColor & TwoWaysColor::operator=(const TwoWaysColor & color)
{
	if (this != &color)
	{
		m_inColor = color.m_inColor;
		m_outColor = color.m_outColor;
	}

	return *this;
	
}

bool TwoWaysColor::operator==(const TwoWaysColor & color)
{
	if (m_inColor == color.m_inColor && m_outColor == color.m_outColor)
		return true;
	return false;
}


TwoWaysColor::~TwoWaysColor()
{
}
