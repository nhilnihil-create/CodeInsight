#include <iostream>
#include <vector>
#include <fstream>
#include <utility>
#include <algorithm>
#include <map>
using namespace std;

#define ll long long
#define MOD 1000000007
ll myabs(ll x)
{
	return (x > 0 ? x : -x);
}



ll Modpow(int x)
{
	ll ans = 1;
	if (x == 0)return ans;
	if (x == 1)return 2;
	ans = Modpow(x / 2);
	ans *= ans;
	if (x % 2 == 1)
	{
		ans *= 2;
	}
	ans %= MOD;
	return ans;
}
int main()
{
	int n = 0;
	cin >> n;
	vector<ll> a(n);
	map<int, int> cnt;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		cnt[a[i]]++;
	}
	bool incons = 0;
	if (n % 2 == 1)
	{
		for (int i = 0; i <= n / 2; i++)
		{
			if ((i == 0 && cnt[2*i] != 1) || (i!=0 && cnt[2*i] != 2))
			{
				incons = true;
				break;
			}
		}
	}
	else
	{
		for (int i = 1; i <= n / 2; i++)
		{
			if (cnt[2 * i - 1] != 2)
			{
				incons = true;
				break;
			}
		}
	}
	if (incons)cout << "0\n";
	else
	{
		cout << Modpow(n / 2) << endl;
	}
	
}
