#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,tune=native")
#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("trapv")
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
const int mod = 1000000007;
const ll inf = 1e18;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main() { //DINIC ORZ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	map<char, int> x;
	string s;
	cin >> s;
	for(auto i : s) x[i]++;
	ll ans = 0;
	for(auto i : x) {
		ans += i.second*(s.size()-i.second);
	}
	ans/=2, ++ans;
	cout << ans << "\n";
}

