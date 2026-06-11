#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin >> s;

	string ans = "";

	for (auto &&c : s)
	{
		if (c == 'B' && !ans.empty())
		{
			ans.pop_back();
		}
		else if (c == '0' || c == '1')
		{
			ans.push_back(c);
		}
	}

	cout << ans << endl;

	return 0;
}