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
	int n = 0;
	cin >> n;
	vector<int> a(n);
	for (auto &i : a)
		cin >> i;
	lli sum = accumulate(a.begin(), a.end(), 0ll);
	lli d = sum / ((1ll * n * (n + 1)) / 2);
	if (sum % ((1ll * n * (n + 1)) / 2) != 0ll)
	{
		cout << "NO" << endl; return 0;
	}
	for (int i = 0; i + 1 < n; ++i)
	{
		lli diff = d + a[i] - a[i + 1];
		if (diff < 0ll || diff % n != 0ll)
		{
			cout << "NO" << endl;
			return 0;
		}
	}
	lli last = d + a[n - 1] - a[0];
	if (last < 0ll || last % n != 0ll)
		cout << "NO";
	else
		cout << "YES";
	cout << endl;
}