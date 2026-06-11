#include <bits/stdc++.h>
const long long INF = LLONG_MAX / 2;
const long long MOD = 1000000007;
const long double PI = 3.1415926;
#define FOR(i, r, n) for(int i=(ll)(r); i<(ll)(n); i++) 
#define REP(i, n) FOR(i, (0), n)
#define ll long long int
using namespace std;
ll ans = 0, sum = 0, n, k, counter = 0, w, h;
string s;
vector<ll> v;
vector<pair<ll, ll>> vp;
vector<vector<ll>> vv(50, vector<ll>(50, INF));

int main() {
	cin >> h >> w;
	REP(i,h)
		REP(j, w) {
		cin >> s;
		if (s == "snuke") {
			cout << static_cast<char>(j + 65) << i + 1 << endl;
			return 0;
		}
	}
}