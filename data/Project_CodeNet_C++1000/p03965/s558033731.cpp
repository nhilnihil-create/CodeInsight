#include <bits/stdc++.h>
using namespace std;

int main()
{
	int g = 0, p = 0, ans = 0;
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == 'p')
		{
			if (p+1 > g) ans--, g++;
			else p++;
		}
		else if (str[i] == 'g')
		{
			if (g >= p+1) ans++, p++;
			else g++;
		}
	}
	cout << ans << endl;
	return 0;
}