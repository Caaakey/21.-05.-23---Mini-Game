#pragma once

class Block
{
public:
	Block(D2D_RECT_F rect);
	~Block();

	void Update();
	void Render();

private:
	BaseTexture* m_Texture;
	D2D_RECT_F m_Rect;

public:
	D2D_RECT_F GetRect() { return m_Rect; }

};

