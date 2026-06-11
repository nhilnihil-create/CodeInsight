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
	int n = 0; lli k = 0ll, g = 0ll;
	cin >> n >> k;
	vector<lli> a(n);
	cin >> a[0]; g = a[0];
	for (int i = 1; i < n; ++i)
	{
		cin >> a[i];
		g = __gcd(g, a[i]);
	}
	if (k % g == 0 && k <= *max_element(a.begin(), a.end()))
		cout << "POSSIBLE";
	else
		cout << "IMPOSSIBLE";
	cout << endl;
}