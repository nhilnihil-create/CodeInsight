#include <bits/stdc++.h>
using namespace std;

int main()
{
	string o, e;
	cin >> o >> e;

	string ans = "";

	for (int i = 0, j = 0; i < o.size() || j < e.size();)
	{
		if (i < o.size())
		{
			ans += o[i];
			i++;
		}

		if (j < e.size())
		{
			ans += e[j];
			j++;
		}
	}

	cout << ans << endl;

	return 0;
}