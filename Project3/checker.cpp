#include<string>
#include<cstdlib>
using namespace std;

class Checker
{
public:

	int getStringLength(string firstStr, string secondStr)
	{
		if(firstStr.length() == secondStr.length())
		{
			return 60;
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
			gapLength = firLength - seco ndLength;
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