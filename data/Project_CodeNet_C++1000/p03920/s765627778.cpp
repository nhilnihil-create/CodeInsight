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
	cin >> n;
	counter = 1;
	while (counter < 10000) {
		sum += counter;
		if (sum >= n) break;
		counter++;
	}
	while (n) {
		if (counter < n) {
			cout << counter << endl;
			n -= counter;
			counter--;
		}
		else {
			cout << n << endl;
			break;
		}
	}
}