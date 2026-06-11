/*The woods are lovely, dark and deep,
But I have promises to keep,
And miles to go before I sleep,
And miles to go before I sleep.*/

//PRABHJOT SINGH A.K.A. PRABHI
//~~~~~conquizztador~~~~~


#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
const int MOD = 1000000007;
const int MOD1 = 998244353;
const int maxn = 100010;
const int lim = (int)1e9;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	int n = s.length();
	int res = n;
	vector<int> a(n);
	for (int i = 0; i < 26; ++i)
	{
		for (int j = 0; j < n; ++j)
			a[j] = (s[j] - 'a' == i) ? 0 : 1;
		int t = n, k = 0;
		while (true)
		{
			bool flag = true;
			for (int j = 0; j < t; ++j)
				if (a[j] == 1)
				{
					flag = false; break;
				}
			if (flag)
			{
				res = min(res, k); break;
			}
			for (int j = 0; j + 1 < t; ++j)
				a[j] = min(a[j], a[j + 1]);
			--t;
			++k;
		}
	}
	cout << res << endl;
}