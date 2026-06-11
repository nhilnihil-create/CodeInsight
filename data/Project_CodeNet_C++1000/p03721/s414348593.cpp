#include<iostream>
#include<string>
#include<map>
using namespace std;
typedef long long ll;
const int Max = 1e5 + 5;
int lst[Max];

int main()
{
	ll n, k;
	cin >> n >> k;
	ll sum = 0, f;
	map<ll, ll> ma;
	for (int i = 1;i <= n;i++)
	{
		ll a, b;
		scanf("%lld%lld", &a, &b);
		ma[a] += b;
	}
	for (auto i = ma.begin();i != ma.end();i++)
	{
		if (sum + i->second >= k)
		{
			cout << i->first;
			break;
		}
		sum += i->second;
	}
}