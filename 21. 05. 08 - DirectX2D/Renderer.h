#pragma once
#include "Transform.h"

class Renderer : public Transform
{
	struct Frame {
		std::vector<D2D_POINT_2U> frames;
		int tick;
		int invokeIndex;
	};

public:
	Renderer(std::string name);
	Renderer(std::string name, std::wstring imageFilePath, UINT fx, UINT fy);
	virtual ~Renderer();

	void Update(int state);
	void Render();

	void AddAnimation(D2D_POINT_2U frames[], int length, int tick, bool isSetAnimation = false, int invokeIndex = -1);
	void SetAnimation(int state);
	void SetDownAnimation(int index);
	void SetIndexPointer(int* pStatus);

private:
	BaseTexture* m_Texture;
	D2D1_SIZE_F m_Size;
	int m_AnimDownIndex;

	Frame m_CurrentFrame;
	int m_CurrentStatus;
	int m_CurrentFrameTime;
	int m_CurrentFrameIndex;

	int* m_AnimIndexPointer;

public:
	std::vector<Frame> AnimFrame;

	float Opacity;
	bool isReverse;

public:
	D2D1_SIZE_F GetSize() { return m_Size; }

};

