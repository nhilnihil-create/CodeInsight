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
	vector<int> a(3);
	vector<int> b(3);
	cin >> a[0] >> a[1] >> a[2];
	sort(a.begin(), a.end());
	if (a[0] == a[2])
		cout << ((a[0] & 1) ? "0" : "-1");
	else
	{
		int res = 0;
		while (true)
		{
			if ((a[0] & 1) || (a[1] & 1) || (a[2] & 1))
				break;
			++res;
			b[0] = (a[0] + a[1]) / 2; b[1] = (a[1] + a[2]) / 2; b[2] = (a[0] + a[2]) / 2;
			sort(b.begin(), b.end());
			a = b;
		}
		cout << res;
	}
	cout << endl;
}