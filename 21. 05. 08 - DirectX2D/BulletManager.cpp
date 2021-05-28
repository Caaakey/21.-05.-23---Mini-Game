#include "stdafx.h"
#include "BulletManager.h"

BulletManager::BulletManager()
{
}

BulletManager::~BulletManager()
{
}

void BulletManager::Update()
{
	for (int i = 0; i < m_Bullets.size(); ++i)
	{
		if (!m_Bullets[i]->Update())
		{
			SAFE_DELETE(m_Bullets[i]);
			m_Bullets.erase(m_Bullets.begin() + i--);
		}
	}
}

void BulletManager::Render()
{
	for (auto i : m_Bullets)
		i->Render();
}

void BulletManager::Shoot(std::string name, float x, float y, float angle, float speed, bool isReverse)
{
	Bullet* pBullet = new Bullet(name, x, y, angle, speed, isReverse);
	m_Bullets.push_back(pBullet);
}

void BulletManager::Shoot(std::string name, float x, float y, UINT fx, UINT fy, int frameSpeed, float angle, float speed, bool isReverse)
{
	Bullet* pBullet = new Bullet(name, x, y, fx, fy, frameSpeed, angle, speed, isReverse);
	m_Bullets.push_back(pBullet);
}

bool BulletManager::IntersectRect(D2D_RECT_F rect)
{
	for (auto* i : m_Bullets) {
		if (Collision::IsInRect(rect, i->GetRect())) return true;
	}

	return false;
}

bool BulletManager::IntersectRectInCircle(D2D_RECT_F rect)
{
	for (auto* i : m_Bullets) {
		if (Collision::isRectInCircle(rect, i->GetEllipse())) return true;
	}

	return false;
}