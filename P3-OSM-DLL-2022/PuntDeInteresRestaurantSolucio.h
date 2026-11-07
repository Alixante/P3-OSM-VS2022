#pragma once

#include <string>
#include "Common.h"
#include "PuntDeInteresBase.h"

class PuntDeInteresRestaurantSolucio : public PuntDeInteresBase

{

private:
    //Coordinate m_coord;
    //std::string m_name;
    std::string m_tipusCuina;
    bool m_wheelchair;

public:
    PuntDeInteresRestaurantSolucio();

    PuntDeInteresRestaurantSolucio(std::string tipusCuina, bool accesPersonesMobReduida, Coordinate coord, std::string name) :
        m_tipusCuina(tipusCuina), m_wheelchair(accesPersonesMobReduida), PuntDeInteresBase(coord, name) {
    }

    std::string getName() override;
    Coordinate getCoord();
    unsigned int getColor() override;

};