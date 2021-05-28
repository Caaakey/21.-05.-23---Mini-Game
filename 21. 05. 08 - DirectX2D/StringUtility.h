#pragma once

class StringUtility
{
public:
	static inline std::string ConvertString(const std::wstring& wstr)
	{
		std::string str;
		for (wchar_t c : wstr)
			str.push_back(static_cast<char>(c));

		return str;
	}

	static inline std::wstring ConvertString(const std::string& str)
	{
		std::wstring wstr;
		return wstr.assign(str.begin(), str.end());
	}
};
