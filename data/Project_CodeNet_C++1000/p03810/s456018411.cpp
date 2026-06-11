#pragma GCC optimize("trapv")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
//using arr = array;
using pi = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vpi = vector<pi>;
using ld = long double;
const int maxn = 1<<18, mod = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
bool solve(vi a) {
	int win = 0, cnt = 0, g = 0, bad = 0;
	for(auto &i : a) {
		cnt += i&1;
		if(i&1) i == 1 ? bad = 1 : --i;
		else win ^= 1;
		g = __gcd(g, i);
	}
	if(win) return 1;
	if(cnt > 1 || bad) return 0;
	
	for(auto &i : a) i /= g;
	return !solve(a);
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vi a(n);
	for(auto &i : a) cin >> i;
	cout << (solve(a)?"First":"Second");
}
