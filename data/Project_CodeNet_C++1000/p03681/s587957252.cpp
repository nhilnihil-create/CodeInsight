#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <algorithm>
#include <math.h> 
#include <set>
#include <map>

using namespace std;

#define ll long long int
#define rep(i, n) for(ll i = 0; i < n; i++)
#define repp(i, n) for(int i = 1; i <= n; i++)
#define sort(v) sort((v).begin(), (v).end())
#define riverse(v) reverse((v).begin(), (v).end())
using vi = vector<int>;
using vs = vector<string>;
using vll = vector<ll>;
using vvi = vector<vi>;
const ll MOD = 1e9 + 7;


int main() {
	int N, M;
	cin >> N >> M;
	ll ans;
	if (N == M) {
		ans = 2;
		for (int i = 1; i <= N; i++) {
			ans = ans * i;
			ans = ans % MOD;
			ans = ans * i;
			ans = ans % MOD;
		}
	}
	else if (N == M + 1) {
		ans = M + 1;
		for (int i = 1; i <= M; i++) {
			ans = ans * i;
			ans = ans % MOD;
			ans = ans * i;
			ans = ans % MOD;
		}
	}
	else if (M == N + 1) {
		ans = N + 1;
		for (int i = 1; i <= N; i++) {
			ans = ans * i;
			ans = ans % MOD;
			ans = ans * i;
			ans = ans % MOD;
		}
	}
	else ans = 0;
	cout << ans << endl;
}