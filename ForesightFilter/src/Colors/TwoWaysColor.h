#pragma once
#include "BaseColor.h"

class TwoWaysColor 
{
public:
	TwoWaysColor();
	TwoWaysColor(BaseColor inColor, BaseColor outColor);
	TwoWaysColor(const TwoWaysColor& color);
	TwoWaysColor& operator=(const TwoWaysColor& color);
	bool operator==(const TwoWaysColor& color);
	~TwoWaysColor();

	BaseColor GetInColor() const { return m_inColor; }
	void SetInColor(BaseColor val) { m_inColor = val; }
	BaseColor GetOutColor() const { return m_outColor; }
	void SetOutColor(BaseColor val) { m_outColor = val; }

private:

	BaseColor m_inColor;
	BaseColor m_outColor;
};

