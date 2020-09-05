#include "src\FilterFactory\FiltersFactory.h"
#include "src\Colors\BaseColor.h"
#include "src\Shapes\Sphere.h"
#include "src\Filters\SphereFilter.h"
#include "opencv2\highgui.hpp"
#include <iostream>





int main()
{
	std::unique_ptr<Sphere> sToFilter = std::make_unique<Sphere>();
	std::unique_ptr<TwoWaysColor> cToFilter = std::make_unique<TwoWaysColor>();
	FiltersFactory* filter = FiltersFactory::GetFactoryInstance();
	
	
	
	auto Spherefilter =  filter->GetShapeFilter<Sphere, TwoWaysColor>("Sphere");
	if (nullptr != Spherefilter)
	{
		std::string path = "RedSphere.png";
		Spherefilter->FilterShape(sToFilter.get(), cToFilter.get(), path);
	}
	
	std::cout <<"InColor Values: " << cToFilter->GetInColor() << "Out Color Values: " << cToFilter->GetOutColor();

	cv::waitKey(0);
	return 0;
}