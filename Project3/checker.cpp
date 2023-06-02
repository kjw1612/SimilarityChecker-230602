#include<string>
#include<cstdlib>
using namespace std;

class Checker
{
public:
	const int MAX_POINT = 60;

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