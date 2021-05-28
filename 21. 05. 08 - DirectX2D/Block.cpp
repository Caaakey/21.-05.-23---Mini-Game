#include "stdafx.h"
#include "Block.h"

Block::Block(D2D_RECT_F rect)
	: m_Texture(nullptr), m_Rect(rect)
{
	m_Texture = _Texture->LoadTexture("Block", L"../_Resources/Block.png");
}

Block::~Block()
{
}

void Block::Update()
{
}

void Block::Render()
{
	m_Texture->Draw(m_Rect.left, m_Rect.top, m_Rect.right - m_Rect.left, m_Rect.bottom - m_Rect.top);
}
