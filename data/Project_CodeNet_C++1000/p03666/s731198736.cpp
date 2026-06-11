
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx2,tune=native")
//#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("trapv")
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using pi = pair<ll, ll>;
const int mod = 7 * 17 * (1 << 23) + 1;
const ll inf = 1e18;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll n, a, b, c, d;
int main() { //DINIC ORZ, FFT ORZ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> a >> b >> c >> d;
	b-=a;
	n--;
	for(ll neg = 0; neg <= n; neg++) {
		ll L = (n-neg)*c-neg*d;
		ll R = (n-neg)*d-neg*c;
		if(b>=L&&b<=R) return cout << "YES", 0;
	}
	cout << "NO\n";
}

