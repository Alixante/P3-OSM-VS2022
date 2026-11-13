#pragma once
#include "Common.h"
#include "pch.h"
#include <vector>
#include "CamiBase.h"

class CamiSolucio : public CamiBase
{
	public:
		std::vector<Coordinate> getCamiCoords() override;
		void addNodeId(std::string id);
		std::vector<std::string>& getRefsNodes(){ return m_refsNodes; }
		void addCoords(Coordinate& coords);

	private:
		std::vector<std::string> m_refsNodes;
		std::vector<Coordinate> m_coordsNodes;

};

