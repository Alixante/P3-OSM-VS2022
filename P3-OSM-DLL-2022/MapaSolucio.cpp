#include "MapaSolucio.h"
#include "PuntDeInteresBotigaSolucio.h"
#include "PuntDeInteresRestaurantSolucio.h"
#include "pch.h"

void MapaSolucio::getPdis(std::vector<PuntDeInteresBase*>& pdis) //Pasar puntos de interes a mapa solución
{
	pdis.clear();

	Coordinate cordenada1 = {41.4918606, 2.146541};
	pdis.push_back(new PuntDeInteresBotigaSolucio("bakery", "", false, cordenada1, "La millor Pastisseria"));

	Coordinate cordenada2 = {41.4902204, 2.1406477};
	pdis.push_back(new PuntDeInteresRestaurantSolucio("regional", true, cordenada2, "El Millor Restaurant"));
}



void MapaSolucio::getCamins(std::vector<CamiBase*>&)
{
	//CamiBase* c = new CamiDerivat();
}



void MapaSolucio::parsejaXmlElements(std::vector<XmlElement>& xmlElements)
{

}

