#pragma once
#include <thread>
#include <iostream>
#include <mutex>
#include "..\Shapes\BaseShape.h"
#include "..\Filters\BaseFilter.h"

class FiltersFactory
{
public:

	static FiltersFactory* GetFactoryInstance()
	{
		if (!m_FactoryInstance)//Singleton double checked locking
		{
			std::unique_lock<std::mutex> lockguad(lockg);
			if (!m_FactoryInstance)
			{
				m_FactoryInstance = new FiltersFactory();
			}
				
		}
		return m_FactoryInstance;
	}

	static FiltersFactory* m_FactoryInstance;

	template <typename DerivedShape, typename DerivedColor>
	BaseFilter<DerivedShape, DerivedColor>* GetShapeFilter(const std::string & shapeName);
	

	
private:
	FiltersFactory();
	~FiltersFactory();

	FiltersFactory(const FiltersFactory& copy) = delete;
	FiltersFactory operator=(const FiltersFactory& copy) = delete;
			
	static std::mutex lockg;

};

template<typename DerivedShape, typename DerivedColor>
inline BaseFilter<DerivedShape, DerivedColor>* FiltersFactory::GetShapeFilter(const std::string & shapeName)
{
	BaseFilter<DerivedShape, DerivedColor>* filter = nullptr;
	if (shapeName == "Sphere")
	{
		filter = new SphereFilter();
	
	}

	return filter;
}
