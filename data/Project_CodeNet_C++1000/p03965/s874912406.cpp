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
	int ans = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (i % 2 == 0)
		{
			if (s[i] == 'p')
				ans -= 1;
		}
		else
		{
			if (s[i] == 'g')
				ans += 1;
		}
	}
	cout << ans << endl;



}
