#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using ll = long long;
using pll = pair<ll,ll>;
using pli = pair<ll,int>;
using pil = pair<int,ll>;
using ld = long double;
using ui = unsigned int;
using ull = unsigned long long;
using ui128 = __uint128_t;
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define lc ind<<1
#define rc ind<<1|1
const int MN = 1e5 + 2, LOG = 17, INF = 1e8;
ll ans[MN];
int main () { 
	int n; 
	scanf ("%d",&n);
	vector<pii> a(n);
	for (int i = 0; i < n; i++) {
		scanf ("%d",&a[i].first); a[i].second = i; 
	}
	sort(all(a),[&](pii b, pii c){return b.first > c.first || (b.first == c.first && b.second < c.second);});
	a.push_back({0,0});
	int lst = n + 1;ll cursum = 0; int cnt = 0, done = 0, lstVal = 0;
	for (int i = 0; i <= n; i++) {
		if (a[i].second > lst) {cnt++; cursum += a[i].first; continue;}
		if (lst == n+1) {lstVal = a[i].first; lst = a[i].second; ++done; continue;}
		ans[lst] = (ll)done * (lstVal - a[i].first) + cursum - (ll)a[i].first * cnt;
		done += cnt + 1; cnt = 0; cursum = 0; lst = a[i].second; lstVal = a[i].first;
	}
	for (int i = 0; i < n; i++) printf ("%lld\n",ans[i]);
    return 0;
}
//1 2 1 3 2 4 2 5 8 1
//1 2 1 2 2 2 2 2 2 1

//1 2 1 2 2 2 2 2 2 1
//9 9 9 8 8 6 6 6 4 4 4 4
