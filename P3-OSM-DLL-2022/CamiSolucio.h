#pragma once
#include "Common.h"
#include "pch.h"
#include <vector>
#include "CamiBase.h"

class CamiSolucio : public CamiBase
{
	public:
		std::vector<Coordinate> getCamiCoords() override;

	private:
		std::vector<std::string> m_refsNodes;
		std::vector<Coordinate> m_coordsNodes;

};

