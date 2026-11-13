#pragma once
#include "Common.h"
#include <vector>
#include "MapaBase.h"
#include "PuntDeInteresBotigaSolucio.h"
#include "PuntDeInteresRestaurantSolucio.h"
#include <unordered_map>

class MapaSolucio : public MapaBase
{
public:
	MapaSolucio() {};

	// SI TE DA TIEMPO, 
	//___________________________________

	void getPdis(std::vector<PuntDeInteresBase*>&) override; //EJERCICIO 3 Pasar puntos de interes a mapa solución 
	void getCamins(std::vector<CamiBase*>&) override;

	//______________________________________________________

	void parsejaXmlElements(std::vector<XmlElement>& xmlElements) override;

private:

	std::unordered_map<std::string, Coordinate> m_nodesVia;
	std::unordered_map<std::string, CamiBase*> m_camins;
	
	std::unordered_map<std::string, PuntDeInteresBase*> m_puntsInteres;


	bool isPdis(std::vector<XmlElement>::iterator it);

	//POR HACER
	//_______________________________________________________

	void insertPdis(XmlElement& x); //COMPLETADO
	void insertCami(XmlElement& x); //EJERCICIO 1
	void insertNode(XmlElement& x); //EJERCICIO 2
	void processNodesIntoCamins(); //LO DEJAS PA LUEGO

	//___________________________________________________


	PuntDeInteresBotigaSolucio* constructBotiga(XmlElement& x);
	PuntDeInteresRestaurantSolucio* constructRestaurant(XmlElement& x);



	bool findValueAtribut(XmlElement& x, const std::string& searchString);
	bool findValueFills(XmlElement& x, const std::string& searchString);
	std::string extractValueAtribut(XmlElement& x, const std::string& searchString);
	std::string extractValueFills(XmlElement& x, const std::string& searchString);
	Coordinate extractCoordinates(XmlElement& x);



};