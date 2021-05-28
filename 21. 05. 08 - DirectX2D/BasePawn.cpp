#include "stdafx.h"
#include "BasePawn.h"

#include "BlockManager.h"

BasePawn::BasePawn(std::string name)
	: Blocks(nullptr)
{
	m_Renderer = new Renderer(name);
}

BasePawn::~BasePawn()
{
	SAFE_DELETE(m_Renderer);
}

void BasePawn::UpdateCheckLocation()
{
	for (auto b : Blocks->GetBlocks()) {
		if (m_Renderer->CheckLocation(b->GetRect()))
		{
			LandingLocation();
			break;
		}
	}

}
