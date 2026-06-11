#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pii;
int main()
{
	ll mx, my;
	scanf("%lld%lld", &mx, &my);
	vector<pii>vec;
	for (int i = 0; i < mx; i++)
	{
		ll z;
		scanf("%lld", &z);
		vec.push_back(make_pair(z, 0));
	}
	for (int i = 0; i < my; i++)
	{
		ll z;
		scanf("%lld", &z);
		vec.push_back(make_pair(z, 1));
	}
	sort(vec.begin(), vec.end());
	ll ans = 0;
	ll nx = mx + 1, ny = my + 1;
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i].second == 0)
		{
			ans += ny*vec[i].first;
			nx--;
		}
		else
		{
			ans += nx*vec[i].first;
			ny--;
		}
	}
	printf("%lld\n", ans);
}