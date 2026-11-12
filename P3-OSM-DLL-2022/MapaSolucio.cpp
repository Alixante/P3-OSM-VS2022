#include "pch.h"

#include <vector>

#include "MapaSolucio.h"

#include "PuntDeInteresBase.h"
#include "PuntDeInteresBotigaSolucio.h"
#include "PuntDeInteresRestaurantSolucio.h"

#include "CamiBase.h"
#include "CamiSolucio.h"
#include <vector>

#include <iostream>

void MapaSolucio::getPdis(std::vector<PuntDeInteresBase*>& pdis) //Pasar puntos de interes a mapa solución
{
	pdis.clear();

	Coordinate cordenada1 = {41.4918606, 2.146541};
	pdis.push_back(new PuntDeInteresBotigaSolucio("bakery", "", false, cordenada1, "La millor Pastisseria"));

	std::cout << "Instanciat Botiga" << std::endl;

	Coordinate cordenada2 = {41.4902204, 2.1406477};
	pdis.push_back(new PuntDeInteresRestaurantSolucio("regional", true, cordenada2, "El Millor Restaurant"));
}


//void MapaSolucio::getCamins(std::vector<CamiSolucio*>& cami)
void MapaSolucio::getCamins(std::vector<CamiBase*>& cami)
{
	cami.clear();
	cami.push_back(new CamiSolucio());

}



void MapaSolucio::parsejaXmlElements(std::vector<XmlElement>& xmlElements)
{

}

