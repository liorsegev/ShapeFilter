#include "FiltersFactory.h"
#include "..\Filters\SphereFilter.h"


FiltersFactory::FiltersFactory()
{
	
}


FiltersFactory::~FiltersFactory()
{
	if (m_FactoryInstance)
	{
		m_FactoryInstance = nullptr;
		delete m_FactoryInstance;
	}
}


FiltersFactory* FiltersFactory::m_FactoryInstance;
std::mutex FiltersFactory::lockg;


