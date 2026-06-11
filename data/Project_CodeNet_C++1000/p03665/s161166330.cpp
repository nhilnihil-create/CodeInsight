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
	int n = 0, p = 0, odd = 0, even = 0;
	cin >> n >> p;
	vector<int> a(n);
	for (auto &i : a)
	{
		cin >> i;
		if (i & 1)
			++odd;
		else
			++even;
	}
	if (odd == 0)
		cout << (p == 0 ? (1ll << n) : 0);
	else
		cout << (1ll << n - 1ll);
	cout << endl;
}