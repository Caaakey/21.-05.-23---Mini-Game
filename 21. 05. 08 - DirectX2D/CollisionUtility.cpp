#include "stdafx.h"
#include "CollisionUtility.h"

namespace Collision
{
	bool IsInRect(D2D_RECT_F from, D2D_RECT_F to)
	{
		if ((from.left <= to.right && from.right >= to.left) &&
			(from.top <= to.bottom && from.bottom >= to.top)) {
			return true;
		}

		return false;
	}
	bool IsInRectPoint(D2D_RECT_F from, D2D_VECTOR_2F to)
	{
		if ((from.left <= to.x && from.right >= to.x) &&
			from.top <= to.y && from.bottom >= to.y)
			return true;

		return false;
	}
	bool IsInCirclePoint(float x, float y, D2D1_ELLIPSE circle)
	{
		float dx = circle.point.x - x;
		float dy = circle.point.y - y;

		//	float p = sqrtf(dx * dx + dy * dy);
		//	pow ?	오른쪽 숫자가 제곱할 개수
		//	제곱! pow(dx, 2) = dx * dx
		float p = (float)sqrt(pow(dx, 2) + pow(dy, 2));

		//	삼항 연산자
		//	p < circle.radiusX ? true : false;
		return p < circle.radiusX;
	}
	bool isRectInCircle(D2D_RECT_F rect, D2D1_ELLIPSE circle)
	{
		if ((rect.left <= circle.point.x && rect.right >= circle.point.x) ||
			(rect.top <= circle.point.y && rect.bottom >= circle.point.y))
		{
			D2D_RECT_F temp = {
				rect.left - circle.radiusX,
				rect.top - circle.radiusX,
				rect.right + circle.radiusX,
				rect.bottom + circle.radiusX
			};

			if ((temp.left <= circle.point.x && temp.right >= circle.point.x) &&
				(temp.top <= circle.point.y && temp.bottom >= circle.point.y))
				return true;
		}
		//	모서리 검사
		else {
			if (IsInCirclePoint(rect.left, rect.top, circle)) return true;
			if (IsInCirclePoint(rect.left, rect.bottom, circle)) return true;
			if (IsInCirclePoint(rect.right, rect.top, circle)) return true;
			if (IsInCirclePoint(rect.right, rect.bottom, circle)) return true;
		}

		return false;
	}
	float GetDistance(float x, float y, float ex, float ey)
	{
		return (float)sqrt(pow(x - ex, 2) + pow(y - ey, 2));
	}
	float GetAngle(float x, float y, float ex, float ey)
	{
		float dx = ex - x;
		float dy = ey - y;

		float angle = atan2(dy, dx) * (180.0f / PI);
		if (angle < 0.0f) angle += 360.0f;

		return DegreeToRadian(angle);
	}
	float DegreeToRadian(float degree)
	{
		return degree * (PI / 180.0f);
	}
	float RadianToDegree(float radian)
	{
		return radian * (180.0f / PI);
	}
}

D2D_RECT_F MakeHelper::GetRect(D2D_VECTOR_2F position, D2D_SIZE_F size)
{
	return { position.x, position.y, position.x + size.width, position.y + size.height };
}

D2D_RECT_F MakeHelper::GetRectCenter(D2D_VECTOR_2F position, D2D_SIZE_F size)
{
	return {
		position.x - (size.width / 2.0f),
		position.y - (size.height / 2.0f),
		position.x + (size.width / 2.0f),
		position.y + (size.width / 2.0f) };
}

float RandomHelper::Random()
{
	return static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
}

float RandomHelper::Random(float num)
{
	return static_cast<float>(rand()) / static_cast<float>(RAND_MAX / num);
}

float RandomHelper::RandomRange(float min, float max)
{
	return static_cast<float>(rand()) / static_cast<float>(RAND_MAX / (max - min)) + min + 1.0f;
}
