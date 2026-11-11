#pragma once
#include "Common.h"
#include <vector>
#include "MapaBase.h"

class MapaSolucio : public MapaBase
{
public:
	void getPdis(std::vector<PuntDeInteresBase*>&) override; //Pasar puntos de interes a mapa solución
	void getCamins(std::vector<CamiBase*>&) override;
	void parsejaXmlElements(std::vector<XmlElement>& xmlElements) override;

};