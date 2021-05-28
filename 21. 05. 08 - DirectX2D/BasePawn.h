#pragma once
#include "Renderer.h"

class BlockManager;
class BasePawn
{
public:
	BasePawn(std::string name);
	virtual ~BasePawn();

	virtual HRESULT Start() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;

protected:
	void UpdateCheckLocation();
	virtual void LandingLocation() = 0;

protected:
	Renderer* m_Renderer;

public:
	BlockManager* Blocks;

public:
	virtual D2D1_RECT_F GetHitRect() { return m_Renderer->GetRect(); }

};

