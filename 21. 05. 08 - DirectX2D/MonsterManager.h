#pragma once

class BasePawn;
class BlockManager;
class MonsterManager
{
public:
	MonsterManager();
	~MonsterManager();

	HRESULT Start(BlockManager* pBlock);
	void Update();
	void Render();

	void AddMonster(BasePawn* pawn);

private:
	BlockManager* m_Blocks;
	std::vector<BasePawn*> m_Monsters;

public:
	bool IntersectCollider(D2D_RECT_F rect);
};

