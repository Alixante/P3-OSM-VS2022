#include "pch.h"
#include "PuntDeInteresBotigaSolucio.h"

PuntDeInteresBotigaSolucio::PuntDeInteresBotigaSolucio()
{
    m_wheelchair = false;
}

std::string PuntDeInteresBotigaSolucio::getName() 
{
    return this->getName();
}


unsigned int PuntDeInteresBotigaSolucio::getColor() 
{
    if (m_tagShopValue == "supermarket")
    {
        return 0xDFFF00;
    }
    else if (m_tagShopValue == "tobacco")
    {
        return 0xFF7F50;
    }
    else if (m_tagShopValue == "bakery")
    {
        if (m_tagOpeningHoursValue == "06:00 - 22:00" && m_wheelchair)
        {
            return 0x4CBB17;
        }
        return 0xFA8072;
    }


    return 0xFFEA00;
}