#pragma once

#include <string>
#include "Common.h"
#include "PuntDeInteresBase.h"

class PuntDeInteresBotigaSolucio : public PuntDeInteresBase

{
private:
	//Coordinate m_coord;
	//std::string m_name;
	std::string m_tagShopValue;
	std::string m_tagOpeningHoursValue;
	bool m_wheelchair;

public:
	PuntDeInteresBotigaSolucio();
	PuntDeInteresBotigaSolucio(std::string tagShopValue, std::string tagOpeningHoursValue, bool wheelchair, Coordinate coord, std::string name):
    m_tagShopValue(tagShopValue), m_tagOpeningHoursValue(tagOpeningHoursValue), m_wheelchair(wheelchair), PuntDeInteresBase(coord, name) {}

	std::string getName() override ;
	Coordinate getCoord();
	unsigned int getColor() override;
};