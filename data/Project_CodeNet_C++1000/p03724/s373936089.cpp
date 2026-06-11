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
	int n = 0, m = 0, x = 0, y = 0;
	cin >> n >> m;
	vector<int> deg(n, 0);
	for (int i = 0; i < m; ++i)
	{
		cin >> x >> y;
		++deg[x]; ++deg[y];
	}
	for (auto &i : deg)
		if (i & 1)
		{
			cout << "NO" << endl;
			return 0;
		}
	cout << "YES" << endl;
}