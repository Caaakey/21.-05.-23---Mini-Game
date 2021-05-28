#pragma once
#include "Bullet.h"

class BulletManager
{
public:
	BulletManager();
	~BulletManager();

private:
	std::vector<Bullet*> m_Bullets;

public:
	void Update();
	void Render();

	void Shoot(std::string name, float x, float y, float angle, float speed, bool isReverse);
	void Shoot(std::string name, float x, float y, UINT fx, UINT fy, int frameSpeed, float angle, float speed, bool isReverse);

	bool IntersectRect(D2D_RECT_F rect);
	bool IntersectRectInCircle(D2D_RECT_F rect);
};

