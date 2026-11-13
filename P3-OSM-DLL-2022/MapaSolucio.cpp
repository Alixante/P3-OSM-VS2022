#include "pch.h"

#include "Util.h"
#include "Common.h"
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
	//Primer pass per trobar les fer a camins
	//afegirem tots a m_puntsInteres i despres afegirem als camins
	//Anirem pels camins d'un en un, treient les refs de m_puntsInteres i afegintlos a 

	std::vector<XmlElement>::iterator it;
	for (it = xmlElements.begin(); it != xmlElements.end(); it++)
	{
		//Si es way, te id_elemnt == "way"
		if (it->id_element == "way")
		{
			insertCami(*it);
		}
		
		//Si es punt interes o cami, id_element = "node"
		else if (it->id_element == "node")
		{

			if (isPdis(it))
			{
				insertPdis(*it);
			}
			else
			{
				insertNode(*it);
			}
		}
	}


}

bool MapaSolucio::isPdis(std::vector<XmlElement>::iterator it)
{
	for (int i = 0; i < it->fills.size(); i++)
	{
		std::pair<std::string, std::string> valorTag =
			Util::kvDeTag(it->fills[i].second);
		if (valorTag.first == "name")
		{
			for (int i = 0; i < it->fills.size(); i++)
			{
				std::pair<std::string, std::string> valorTag =
					Util::kvDeTag(it->fills[i].second);

				if (valorTag.first == "highway" || valorTag.first == "public_transport"
					|| valorTag.first == "entrance" || valorTag.first == "access")
				{
					return false;
				}
			}
			return true;
		}
	}
	return false;
}

//Los pdis no tienen ni highway ni public transport ni entrance y tienen el tag name

void MapaSolucio::insertPdis(XmlElement& x)
{

	PuntDeInteresBase* pdis;
	std::string ref = extractValueAtribut(x, "id");
	//Separar botiga de restaurant

	if (findValueFills(x, "amenity"))
	{
		pdis = constructRestaurant(x);
	}

	else if(findValueFills(x, "shop"))
	{
		pdis = constructBotiga(x);
	}

	m_puntsInteres.insert(std::make_pair(ref, pdis));
}

void MapaSolucio::insertCami(XmlElement& x)
{
	//AÑADE EL CAMINO CON SU REF DE KEY Y SU CAMISOLUCIO DE VALOR A m_camins en MapaSolucio
	//PONE TODOS LOS REFS DE NODOS DE CAMINO EN m_refsNodes de CamiSolucio
}

void MapaSolucio::insertNode(XmlElement& x)
{
	//AÑADE EL NODO CON SU REF COMO KEY Y SUS COORDS COMO VALOR A m_nodesVIa de MapaSolucio

}

void MapaSolucio::processNodesIntoCamins()
{
	// RECORRE TODOS LOS CAMINOS EN m_camins. 
	// MIRA LAS REFS DE TODOS LOS NODOS GUARDADOS EN m_refsNodes de CamiSolucio,
	// LOS BUSCA EN m_nodesVia de MapaSOlucio USANDO EL REF, Y LOS METE EN m_coordsNodes de CamiSolucio
}

PuntDeInteresBotigaSolucio* MapaSolucio::constructBotiga(XmlElement& x)
{
	
	std::string name = extractValueAtribut(x, "name");
	Coordinate coords = extractCoordinates(x);
	std::string shopValue = extractValueFills(x, "shop");
	std::string opening_hours;
	std::string wheelchairValue;
	bool wheelchair = false;;
	if (findValueFills(x, "wheelchair"))
	{
		wheelchairValue = extractValueFills(x, "wheelchair");
		
	}
	if (wheelchairValue == "yes")
	{
		wheelchair = true;
	}

	if (findValueFills(x, "opening_hours"))
	{
		opening_hours = extractValueFills(x, "opening_hours");
	}
	

	return new PuntDeInteresBotigaSolucio(shopValue, opening_hours,
		wheelchair, coords, name);
}

PuntDeInteresRestaurantSolucio* MapaSolucio::constructRestaurant(XmlElement& x)
{
	std::string name = extractValueAtribut(x, "name");
	Coordinate coords = extractCoordinates(x);
	std::string tipusCuina;
	std::string wheelchairValue;
	bool wheelchair = false;;

	if (findValueFills(x, "wheelchair"))
	{
		wheelchairValue = extractValueFills(x, "wheelchair");

	}
	if (wheelchairValue == "yes")
	{
		wheelchair = true;
	}
	if (findValueFills(x, "cuisine"))
	{
		tipusCuina = extractValueFills(x, "cuisine");
	}

	return new PuntDeInteresRestaurantSolucio(tipusCuina, wheelchair, coords, name);
}


bool MapaSolucio::findValueAtribut(XmlElement& x, const std::string& searchString)
{
	for (int i = 0; i < x.atributs.size(); i++)
	{
		if (x.atributs[i].first == searchString)
		{
			return true;
		}
	}
}
bool MapaSolucio::findValueFills(XmlElement& x, const std::string& searchString)
{
	for (int i = 0; i < x.fills.size(); i++) {
		// Iterem i avaluem tots els fills que son tags
		if (x.fills[i].first == "tag") {
			// Emmagatzemem el valor d’aquest tag
			std::pair<std::string, std::string> valorTag =
				Util::kvDeTag(x.fills[i].second);
			// Comprovem que es el tag que busquem
			if (valorTag.first == searchString) {
				//permetMobilitatReduida =
					//(valorTag.second == "yes") ? true : false;
				return true;
			}
		}
	}
	return false;
}

std::string MapaSolucio::extractValueAtribut(XmlElement& x, const std::string& searchString)
{
	for (int i = 0; i < x.fills.size(); i++)
	{
		if (x.atributs[i].first == searchString)
		{
			return x.atributs[i].second;
		}
	}
}


std::string MapaSolucio::extractValueFills(XmlElement& x, const std::string& searchString)
{
	for (int i = 0; i < x.fills.size(); i++) {
		// Iterem i avaluem tots els fills que son tags
		if (x.fills[i].first == "tag") {
			// Emmagatzemem el valor d’aquest tag
			std::pair<std::string, std::string> valorTag =
				Util::kvDeTag(x.fills[i].second);
			// Comprovem que es el tag que busquem
			if (valorTag.first == searchString) {
				//permetMobilitatReduida =
					//(valorTag.second == "yes") ? true : false;
				return valorTag.second;
			}
		}
	}

}

Coordinate MapaSolucio::extractCoordinates(XmlElement& x)
{
	//Trobar coords

	Coordinate coords;
	for (int i = 0; i < x.atributs.size(); i++)
	{
		if (x.atributs[i].first == "lat")
		{
			coords.lat = std::stod(x.atributs[i].second);
		}
		else if (x.atributs[i].first == "lon")
		{
			coords.lon = std::stod(x.atributs[i].second);
		}
	}

	return coords;
}