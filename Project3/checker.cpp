#include<string>
using namespace std;

class Checker
{
public:
	int getStringLength(string firstStr, string secondStr)
	{
		int gapLength = 0;
		int minLength;

		if (firstStr.length() >= secondStr.length()) {
			gapLength = firstStr.length() - secondStr.length();
			minLength = secondStr.length();
		}
		else
		{
			gapLength = secondStr.length() - firstStr.length();
			minLength = firstStr.length();
		}

		return (1 - gapLength / minLength) * 60;
	}
};