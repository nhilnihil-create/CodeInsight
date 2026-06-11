#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pii;
int main()
{
	int num, gen;
	scanf("%d%d", &num, &gen);
	vector<pii>v;
	ll sum = 0;
	for (int i = 0; i < num; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		v.push_back(make_pair(za, zb));
		if ((gen&za) == za)sum += zb;
	}
	ll maxi = sum;
	for (int i = 29; i >= 0; i--)
	{
		if (0 == (gen&(1 << i)))continue;
		ll mok = (gen - (1 << i)) | ((1 << i) - 1);
		ll s = 0;
		for (int j = 0; j < num; j++)
		{
			if ((mok&v[j].first) == v[j].first)s += v[j].second;
		}
		maxi = max(maxi, s);
	}
	printf("%lld\n", maxi);
}