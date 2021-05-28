#pragma once

#define PI 3.141592f

namespace Collision
{
	bool IsInRect(D2D_RECT_F from, D2D_RECT_F to);
	bool IsInRectPoint(D2D_RECT_F from, D2D_VECTOR_2F to);

	bool IsInCirclePoint(float x, float y, D2D1_ELLIPSE circle);
	bool isRectInCircle(D2D_RECT_F rect, D2D1_ELLIPSE circle);

	float GetDistance(float x, float y, float ex, float ey);
	float GetAngle(float x, float y, float ex, float ey);
	float DegreeToRadian(float degree);
	float RadianToDegree(float radian);
}

namespace MakeHelper
{
	D2D_RECT_F GetRect(D2D_VECTOR_2F position, D2D_SIZE_F size);
	D2D_RECT_F GetRectCenter(D2D_VECTOR_2F position, D2D_SIZE_F size);
}

namespace RandomHelper
{
	float Random();
	float Random(float num);
	float RandomRange(float min, float max);
}
