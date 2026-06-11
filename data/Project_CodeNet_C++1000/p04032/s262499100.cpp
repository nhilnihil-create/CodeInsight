#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{

	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt" , "r" , stdin);
// 	freopen("output.txt" , "w" , stdout);
// #endif

	string s;
	cin >> s;
	int a, b, f = 0;
	vector<int>v[26];
	for (int i = 0; i < s.length(); i++)
	{
		v[s[i] - 97].push_back(i + 1);
	}
	for (int i = 0; i < 26; i++)
	{
		if (v[i].size() > 0)
		{
			int p = v[i][0], c = v[i][0], count = 0;
			for (int j = 0; j < v[i].size(); j++)
			{

				if (v[i][j] - c <= 2)
				{
					c = v[i][j];
					count++;
				}
				if (count > (c - p + 1) / 2 && ((c - p + 1) >= 2))
				{
					f = 1;
					a = p;
					b = c;
					break;
				}
				else
				{
					p = v[i][j];
					c = v[i][j];
					count = 1;
				}

			}
			if (f)
				break;
		}
	}
	if (!f)
		cout << -1 << " " << -1 << endl;
	else
		cout << a << " " << b << endl;



}
