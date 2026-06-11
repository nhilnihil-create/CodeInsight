# include <iostream>
# include <algorithm>
# include <vector>
# include <string>
# include <set>
# include <map>
# include <cmath>
# include <iomanip>
# include <functional>
# include <utility>
# include <stack>
# include <queue>
# include <list>
# include <bitset>
# include <complex>
#include<limits.h>
#include<unordered_map>
#include<unordered_set>
#include<deque>
#include<cstdio>
typedef long long int ll;
using namespace std;
#define FOR(i,a,n) for(ll i=(ll)a;i<(ll)n;++i)
#define TFOR(i,n)FOR(i,0,n)
#define ALL(x) x.begin(),x.end()
const int INF = 1LL << 30;
const ll LLINF = 1LL << 60;
int main() {
	ll nowmax = 1;
	ll N, ans = 0;
	cin >> N;
	TFOR(i, N) {
		ll n; cin >> n;
		if (i == 0)ans += (n - 1);
		else {
			ans += (n - 1) /(nowmax+1);
			if ((n - 1) / (nowmax + 1 )== 0)nowmax =max(nowmax,n);
		}
	}
	cout << ans << endl;
	return 0;
}