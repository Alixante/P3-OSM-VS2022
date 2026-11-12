#pragma once
#include "Common.h"
#include <vector>
#include "MapaBase.h"

#include <unordered_map>

class MapaSolucio : public MapaBase
{
public:
	MapaSolucio() {};
	void getPdis(std::vector<PuntDeInteresBase*>&) override; //Pasar puntos de interes a mapa solución
	void getCamins(std::vector<CamiBase*>&) override;
	void parsejaXmlElements(std::vector<XmlElement>& xmlElements) override;

private:

	std::unordered_map<std::string, Coordinate> m_nodesVia;
	std::unordered_map<std::string, CamiBase*> m_camins;
	
	std::unordered_map<std::string, PuntDeInteresBase*> m_puntsInteres;

};