#include<iostream>
#include<algorithm>
#include<functional>
#include <string>
#include<iomanip>
#include<cstdio>
#include<math.h>
#include<stack>
#include<queue>
#include<cstring>
#include<vector>
typedef long long int ll;
#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define EREP(i,n) for(int i=(n-1);i>=0;--i)
#define D(n,retu) REP(i,n){cin>>retu[i];}
#define mod 1000000007
#define MIN -93193111451418101
#define INF 931931114518101
using namespace std;
typedef pair<ll, ll>P;
template<typename T>
void fill_all(T& arr, const T& v) {
	arr = v;
}
template<typename T, typename ARR>
void fill_all(ARR& arr, const T& v) {
	for (auto& i : arr) { fill_all(i, v); }
}
#define MAX_NUM 50
long long comb[MAX_NUM + 1][MAX_NUM + 1];

ll par[100000], depth[100000];
static void calc_comb()
{
	for (uint32_t i = 0; i <= MAX_NUM; i++) {
		for (uint32_t j = 0; j <= i; j++) {
			if ((j == 0) || (i == j)) {
				comb[i][j] = 1;
			}
			else {
				comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
			}
		}
	}
}


//------------------変数-----------------------//
ll n, d, h, w, goukei[1030] = {};
P p[100001];
vector<ll> v;
vector<vector<ll>> block(100001);
//-------------------関数----------------------//
ll check(ll x, ll y) {
	if (x < 1 || y < 1 || x >= w-1 || y >= h-1) { return 114; }
	ll cnt = 0;
	for (ll i = y - 1; i < y + 2; i++)
	{
		vector<ll>::iterator iter = lower_bound(v.begin(), v.end(), i);
		if (*iter == i&&*iter!=INF) {
			ll point = distance(v.begin(), iter);
			for (ll j = x - 1; j < x + 2; j++)
			{
				vector<ll>::iterator yiter = lower_bound(block[point].begin(), block[point].end(), j);
				if (*yiter == j&&*yiter!=INF) {
					cnt++;
				}
			}
		}
	}
	return cnt;
}
int main() {
	cin >> h >> w >> n;
	REP(i, n) {
		cin >> p[i].first >> p[i].second; p[i].second--; p[i].first--;
	}
	sort(p, p + n);
	ll mae = -1, hoge = -1;
	REP(i, n) {
		if (p[i].first != mae) {
			v.push_back(p[i].first);
			hoge++;
			mae = p[i].first;
		}
		block[hoge].push_back(p[i].second);
	}
	v.push_back(INF);
	REP(i, 100000) {
		block[i].push_back(INF);
	}
	REP(a, hoge + 1) {
		REP(b, block[a].size()-1) {
			for (ll i = v[a] - 1; i < v[a] + 2; i++)
			{
				for (ll j = block[a][b] - 1; j < block[a][b] + 2; j++)
				{
					goukei[check(j, i)]++;
				}
			}
		}
	}
	ll izryt = 0;
	for (ll i = 1; i < 10; i++)
	{
		goukei[i] /= i;
		izryt += goukei[i];
	}
	cout << (h - 2)*(w - 2) - izryt << endl;
	for (ll i = 1; i < 10; i++)
	{
		cout << goukei[i] << endl;
	}

	return 0;
}