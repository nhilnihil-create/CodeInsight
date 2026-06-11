#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<string>
#include<cmath>
#include<cstring>
#include<queue>
#include<map>
#include<climits>
#include<set>

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)
using namespace std;
typedef pair<int, int> pii;
typedef long long int ll;
typedef pair<ll, ll> pll;
//int dx[4] = { 1,0,0,-1 };
//int dy[4] = { 0,1,-1,0 };
#define MOD 1000000007
#define ARRAY_MAX 1005

const int INF = 1e9 + 7;


int main(){


	ios::sync_with_stdio(false);
	cin.tie(0);

	ll h, w;
	cin >> w >> h;
	vector<pll> a;
	for (int i = 0; i < w; i++)
	{
		ll v;
		cin >> v;
		a.push_back(pii(v, 0));
	}

	for (ll i = 0; i < h; i++)
	{
		ll v;
		cin >> v;
		a.push_back(pii(v, 1LL));
	}
	sort(a.begin(), a.end());

	h++;
	w++;//始めは(h+1)行、(w+1)列引く必要がある

	ll ans = 0;

	for (ll i = 0; i < a.size(); i++)
	{
		if (a[i].second == 0LL)
		{
			//横線
			ans += a[i].first * h;
			w--;
		}
		else
		{
			//縦線
			ans += a[i].first * w;
			h--;
		}

	}
	cout << ans << endl;
	

	return 0;
}
