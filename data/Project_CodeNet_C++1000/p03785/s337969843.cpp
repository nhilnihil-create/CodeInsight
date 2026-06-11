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
	int n = 0, res = 0; lli c = 0ll, k = 0ll;
	cin >> n >> c >> k;
	vector<lli> t(n);
	for (auto &i : t)
		cin >> i;
	sort(t.begin(), t.end());
	for (int i = 0; i < n;)
	{
		++res; int j = i + 1, ct = 1;
		while (ct < c && j < n && t[j] <= t[i] + k)
		{
			++j; ++ct;
		}
		i = j;
	}
	cout << res << endl;
}