#include "stdafx.h"
#include "BlockManager.h"

BlockManager::BlockManager()
{
}

BlockManager::~BlockManager()
{
	for (auto b : m_Blocks)
		SAFE_DELETE(b);
}

HRESULT BlockManager::Start()
{
	//	Floor
	m_Blocks.push_back(new Block(
		D2D1::RectF(-10.0f, (float)_Application->Height - 60.0f, (float)_Application->Width + 10.0f, (float)_Application->Height)));

	//	Left block
	m_Blocks.push_back(new Block(
		D2D1::RectF(-10.0f, 500.0f - 60.0f, 200.0f, 500.0f)));

	//	Right block
	m_Blocks.push_back(new Block(
		D2D1::RectF((float)_Application->Width - 190.0f, 500.0f - 60.0f, (float)_Application->Width + 10.0f, 500.0f)));

	//	Middle block
	m_Blocks.push_back(new Block(
		D2D1::RectF(240.0f, 300.0f - 60.0f, (float)_Application->Width - 240.0f, 300.0f)));

	return S_OK;
}

void BlockManager::Update()
{
}

void BlockManager::Render()
{
	for (auto b : m_Blocks)
		b->Render();
}
