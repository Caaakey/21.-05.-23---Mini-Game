#pragma once
#include "Block.h"

class BlockManager
{
public:
	BlockManager();
	~BlockManager();

	HRESULT Start();
	void Update();
	void Render();

private:
	std::vector<Block*> m_Blocks;

public:
	std::vector<Block*> GetBlocks() { return m_Blocks; }
	

};

