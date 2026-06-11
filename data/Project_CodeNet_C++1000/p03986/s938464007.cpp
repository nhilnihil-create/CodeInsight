#include<iostream>
#include<string>
using namespace std;
int solve(string str)
{
	int pos = 0;
	int s = 0;
	int t = 0;
	int ans = str.length();
	while (pos < str.length())
	{
		bool ju = false;
		while (pos < str.length() && str.at(pos) == 'S')
		{
			ju = true;
			pos++;
			s++;
		}
		while (ju && pos < str.length() && str.at(pos) == 'T')
		{
			pos++;
			t++;
		}
		if (t == s)
		{
			ans -= 2 * s;
			t = 0, s = 0;
		}
		else if (s > t)
		{
			ans -= 2 * t;
			s -= t, t = 0;
		}
		else
		{
			ans -= 2 * s;
			s = 0; t = 0;
		}
		if (!ju)
			pos++;
	}
	return ans;
}
int main()
{
	string str;
	cin >> str;
	cout << solve(str);
}