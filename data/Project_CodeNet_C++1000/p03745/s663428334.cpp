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
	int n = 0, typ = 0, ct = 0;
	cin >> n;
	vector<int> a(n);
	for (auto &i : a)
		cin >> i;
	for (int i = 0; i < n; ++i)
	{
		if (i == 0)
			++ct;
		else if (!typ)
		{
			if (a[i] > a[i - 1])
				typ = 1;
			else if (a[i] < a[i - 1])
				typ = -1;
		}
		else
		{
			if (typ == 1)
			{
				if (a[i] < a[i - 1])
				{
					typ = 0; ++ct;
				}
			}
			else
			{
				if (a[i] > a[i - 1])
				{
					typ = 0; ++ct;
				}
			}
		}
	}
	cout << ct << endl;
}