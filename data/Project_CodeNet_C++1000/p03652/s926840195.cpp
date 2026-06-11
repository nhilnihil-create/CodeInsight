//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx2,tune=native")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("trapv")
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pi = pair<ll, ll>;
const int mod = 7*17*(1<<23) + 1;
const ll inf = 1e18;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, m;
vector<int> a[331];
int main() { //DINIC ORZ, FFT ORZ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i <n ;i++) {
		a[i].resize(m);
		for(auto &j : a[i]) cin >> j, j--;
		reverse(all(a[i]));
	}
	int ans = n;
	bool cont = true;
	vi cnt;
	bitset<2000> rem;
	while(cont) {
		int cur = 0, x = 0;
		cnt.assign(m, 0);
		for(int i = 0; i < n; i++) {
			if(++cnt[a[i].back()] > cur) {
				cur = cnt[a[i].back()];
				x = a[i].back();
			}
		}
		rem.set(x);
		ans = min(ans, cur);
		for(int i = 0; i < n; i++) {
			while(!a[i].empty()&&rem[a[i].back()]) a[i].pop_back();
			cont &= !a[i].empty();
		}
	}
	cout << ans;
}
