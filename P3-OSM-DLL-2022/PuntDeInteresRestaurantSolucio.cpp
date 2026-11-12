#include "pch.h"
#include "PuntDeInteresRestaurantSolucio.h"


PuntDeInteresRestaurantSolucio::PuntDeInteresRestaurantSolucio()
    : PuntDeInteresBase() {
    m_tipusCuina = "";
    m_wheelchair = false;
}

std::string PuntDeInteresRestaurantSolucio::getName()
{
    return this->getName();
}


unsigned int PuntDeInteresRestaurantSolucio::getColor()
{

    if (m_tipusCuina == "pizza" && m_wheelchair == true)
    {
        return 0x7FFFD4;
    }
    else if (m_tipusCuina == "chinese")
    {
        return 0x00FFFF;
    }
    else if (m_wheelchair == true)
    {
        return 0x5D3FD3;
    }
    else
    {
        return PuntDeInteresBase::getColor();
    }

}