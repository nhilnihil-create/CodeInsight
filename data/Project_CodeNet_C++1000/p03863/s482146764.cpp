
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
	vector<int>v[26];
	for (int i = 0; i < s.length(); i++)
	{
		v[s[i] - 97].push_back(i + 1);
	}
	int mx = 0, a = 1, b = s.length();
	for (int i = 0; i < 26; i++)
	{
		if (v[i].size() > 1)
		{
			if ( v[i][v[i].size() - 1] - v[i][0] > mx)
			{
				mx = v[i][v[i].size() - 1] - v[i][0] ;
				a = v[i][0];
				b = v[i][v[i].size() - 1];
			}
		}
	}
	// cout << mx << endl;
	if (mx == 0)
	{
		if ((s.length() - 2) % 2)
			cout << "First" << endl;
		else
			cout << "Second" << endl;
	}
	else
	{
		mx -= 2;
		if (a != 1)
			mx += a - 2;
		if (b != s.length())
			mx += s.length() - b - 1 ;
		if(a!=1&&b!=s.length())
			mx+=3;
		if (mx % 2)
			cout << "First" << endl;
		else
			cout << "Second" << endl;
	}
	//cout << mx << endl;


}
