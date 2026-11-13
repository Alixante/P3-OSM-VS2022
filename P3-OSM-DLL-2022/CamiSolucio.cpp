//#include "Common.h"
#include "pch.h"
#include <vector>
#include "CamiSolucio.h"

std::vector<Coordinate> CamiSolucio::getCamiCoords()
{
    return m_coordsNodes;
}

void CamiSolucio::addNodeId(std::string id)
{
    m_refsNodes.push_back(id);
}

void CamiSolucio::addCoords(Coordinate& coords)
{
    m_coordsNodes.push_back(coords);
}


