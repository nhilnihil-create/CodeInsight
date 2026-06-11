#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
int main()
{
	string S;
	cin >> S;
	map<char, int> counter;
	rep(i, S.size())
	{
		counter[S[i]]++;
	}

	int w = counter['W'];
	int e = counter['E'];
	int n = counter['N'];
	int s = counter['S'];

	bool judge1 = false;
	if (w == 0 && e == 0)
	{
		judge1 = true;
	}
	else if (w > 0 && e > 0)
	{
		judge1 = true;
	}

	bool judge2 = false;
	if (n == 0 && s == 0)
	{
		judge2 = true;
	}
	else if (n > 0 && s > 0)
	{
		judge2 = true;
	}

	if (judge1 && judge2)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
	return 0;
}