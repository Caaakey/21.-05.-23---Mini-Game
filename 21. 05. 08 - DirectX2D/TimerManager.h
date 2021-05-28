#pragma once
#include <map>

class TimerManager
{
	struct StopWatch
	{
		float CurrentTime;
		float MaxTime;
		bool isCheck;
	};

public:
	TimerManager();
	static TimerManager* Get() {
		static TimerManager instance;
		return &instance;
	}

private:
	bool m_IsHardware;

	float m_TimeScale;
	float m_TimeElapsed;
	__int64 m_PreroidTime;
	__int64 m_LastTime;
	__int64 m_CurrentTime;

	unsigned long m_FrameRate;
	unsigned long m_FPSFrameCount;

	float m_FPSTimeElapsed;
	float m_WorldTime;

	std::map<std::string, StopWatch> m_StopWatch;

public:
	inline float GetWorldTime() const { return m_WorldTime; }
	inline float GetFPSTime() const { return (float)m_FrameRate; }
	inline float GetElapsedTime() const { return m_TimeElapsed; }

public:
	void UpdateTime(float frameLock = 60.0f);
	void DrawFPSTime();

	void SetTimer(std::string name, float second);
	bool CheckTime(std::string name);
	float GetCurrentSecondTime(std::string name);
};

#define _Timer TimerManager::Get()
