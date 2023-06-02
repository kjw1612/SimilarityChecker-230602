#include<string>
#include<cstdlib>
using namespace std;

class Checker
{
public:
	const int MAX_POINT = 60;
	const int MAX_ALPHA_POINT = 40;
	const int MAX_ALPHA_NUM = 26;

	bool checkAssertAlpha(string firstStr, string secondStr)
	{
		for (int i = 0; i < firstStr.length(); i++)
		{
			if (firstStr[i] < 'A' || firstStr[i] > 'Z') return true;
		}

		for (int i = 0; i < secondStr.length(); i++)
		{
			if (secondStr[i] < 'A' || secondStr[i] > 'Z') return true;
		}

		return false;
	}

	int getStringAlphaCompare(string firstStr, string secondStr)
	{
		if(checkAssertAlpha(firstStr, secondStr))
		{
			return -1;
		}

		if(checkSameUsedAlpha(firstStr, secondStr))
		{
			return MAX_ALPHA_POINT;
		}
		else if(checkAllDiffrentUsedAlpha(firstStr, secondStr))
		{
			return 0;
		}
		
		return checkPartialPoint(firstStr, secondStr);
	}

	bool checkSameUsedAlpha(string firstStr, string secondStr)
	{
		if (getUsedAlphaPosition(firstStr) == getUsedAlphaPosition(secondStr)) return true;
		return false;
	}

	int checkAllDiffrentUsedAlpha(string firstStr, string secondStr)
	{
		if (getUsedAlphaPosition(firstStr) & getUsedAlphaPosition(secondStr) == 0) return true;
		return false;
	}

	int getUsedAlphaPosition(string alphaStr)
	{
		int usedAlpha = 0;

		for(int i = 0;i < alphaStr.length(); i++)
		{
			usedAlpha |= 1 << (alphaStr[i] - 'A');
		}

		return usedAlpha;
	}

	int checkPartialPoint(string firstStr, string secondStr)
	{
		int totalUsedAlpha = getUsedAlphaPosition(firstStr) | getUsedAlphaPosition(secondStr);
		int samUsedAlpha = getUsedAlphaPosition(firstStr) & getUsedAlphaPosition(secondStr);
		int totalUsedAlphaCnt = getUsedAlphaCount(totalUsedAlpha);
		int samUsedAlphaCnt = getUsedAlphaCount(samUsedAlpha);

		return ((double)samUsedAlphaCnt / (double)totalUsedAlphaCnt) * MAX_ALPHA_POINT;
	}

	int getUsedAlphaCount(int usedAlpha)
	{
		int usedCount = 0;
		for(int i = 0;i < MAX_ALPHA_NUM; i++)
		{
			if((usedAlpha & (1 << i)) != 0)
			{
				usedCount++;
			}
		}
		return usedCount;
	}

	int getStringLength(string firstStr, string secondStr)
	{
		if(firstStr.length() == secondStr.length())
		{
			return MAX_POINT;
		}
		else if(firstStr.length() > secondStr.length())
		{
			if (firstStr.length() / secondStr.length() >= 2) return 0;
		}
		else if (firstStr.length() <  secondStr.length())
		{
			if (secondStr.length() / firstStr.length() >=  2) return 0;
		}
		else
		{
			return checkPartialPoint(firstStr.length(), secondStr.length());
		}
	}

	int checkPartialPoint(int firLength, int secondLength)
	{
		int gapLength = 0;
		int minLength;

		if (firLength >= secondLength) 
		{
			gapLength = firLength - secondLength;
			minLength = secondLength;
		}
		else
		{
			gapLength = secondLength - firLength;
			minLength = firLength;
		}

		return (1 - gapLength / minLength) * 60;
	}
};