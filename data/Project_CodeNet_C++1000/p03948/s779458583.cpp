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
//-------------------関数----------------------//

int main() {
	ll n, t, retu[100000] = {}, saidai[100000] = {}, saishou[100000] = {};
	cin >> n >> t;
	REP(i, n) { cin >> retu[i]; }
	ll maxa = 0;
	for (ll i = n-1; i >=1; i--)
	{
		saidai[i-1] = max(maxa, retu[i]);
		maxa = max(maxa, retu[i]);

	}
	ll mini = INF;
	REP(i, n - 1) {
		saishou[i] = min(mini, retu[i]);
		mini = min(retu[i], mini);
	}
	ll izryt = 0;
	for (ll i = 0; i < n-1; i++)
	{
		izryt = max(izryt, saidai[i] - saishou[i]);
	}
	ll cnt = 0;
	for (ll i = 0; i < n-1; i++)
	{
		if (izryt == saidai[i] - retu[i])
			cnt++;
	}
	cout << cnt << endl;
	return 0;
}