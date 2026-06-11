#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll get(ll d, vector<ll>v1, vector<ll>v2, ll t)
{
	ll now = 0, na = 0, nb = 0;
	int pa = v1.size() - 1, pb = 0;
	//for (int i = 0; i < v1.size(); i++)printf("%lld ", v1[i]); printf("\n");
	//for (int i = 0; i < v2.size(); i++)printf("%lld ", v2[i]); printf("\n");
	for (;;)
	{
		if (d == 1)
		{
			ll x = v2[pb] - nb;
			if (x > t)
			{
				now += t;
				break;
			}
			pb++;
			nb += x;
			now += x;
			d = 2;
			t -= x;
		}
		else
		{
			ll x = na - v1[pa];
			if (x > t)
			{
				now -= t;
				break;
			}
			pa--;
			na -= x;
			now -= x;
			d = 1;
			t -= x;
		}
		//printf("---%lld\n", now);
	}
	return now;
}
typedef pair<ll, ll>pii;
ll INF = 1000000000000000000LL;
int main()
{
	int num;
	ll len, tim;
	scanf("%d%lld%lld", &num, &len, &tim);
	len *= 4;
	tim *= 4;
	tim--;
	vector<pii>v;
	for (int i = 0; i < num; i++)
	{
		ll za, zb;
		scanf("%lld%lld", &za, &zb);
		za *= 4;
		v.push_back(make_pair(za, zb));
	}
	vector<ll>v1, v2;
	for (int i = 0; i < num; i++)
	{
		if (v[i].second == 1)
		{
			ll x = v[0].first - v[i].first;
			if (x <= 0)x += len;
			v1.push_back(-x);
			v1.push_back(-x - len);
			v1.push_back(-x - len - len);
		}
		else
		{
			ll x = v[i].first - v[0].first;
			if (x <= 0)x += len;
			v2.push_back(x);
			v2.push_back(x + len);
			v2.push_back(x + len + len);
		}
	}
	v1.push_back(-INF), v2.push_back(INF);
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	ll zt = (v[0].first + len + get(v[0].second, v1, v2, len + len) / 2) % len;
	//printf("%lld\n", zt);
	ll low = lower_bound(v.begin(), v.end(), make_pair(zt, -1LL)) - v.begin();
	ll now = low*(tim / len) % num;
	tim %= len;
	v1.clear(), v2.clear();
	for (int i = 0; i < num; i++)
	{
		if (v[i].second == 1)
		{
			ll x = v[now].first - v[i].first;
			if (x <= 0)x += len;
			v1.push_back(-x);
			v1.push_back(-x - len);
			v1.push_back(-x - len - len);
		}
		else
		{
			ll x = v[i].first - v[now].first;
			if (x <= 0)x += len;
			v2.push_back(x);
			v2.push_back(x + len);
			v2.push_back(x + len + len);
		}
	}
	v1.push_back(-INF), v2.push_back(INF);
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	ll ans = (v[now].first + len + get(v[now].second, v1, v2, tim + tim) / 2) % len;
	vector<ll>ret;
	for (int i = 0; i < num; i++)
	{
		if (v[i].second == 1)ret.push_back((v[i].first + tim) % len);
		else ret.push_back((v[i].first + len - tim) % len);
	}
	sort(ret.begin(), ret.end());
	low = lower_bound(ret.begin(), ret.end(), ans) - ret.begin();
	vector<ll>rr;
	for (int i = low; i < num; i++)rr.push_back(ret[i]);
	for (int i = 0; i < low; i++)rr.push_back(ret[i]);
	for (int i = 0; i < num; i++)
	{
		if (rr[i] % 4 == 1)rr[i] = (rr[i] - 1) / 4 % (len / 4);
		else rr[i] = (rr[i] + 1) / 4 % (len / 4);
		printf("%lld\n", rr[i]);
	}
}