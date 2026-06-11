#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <set>


using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long ll;
typedef vector<ll> VL;
typedef pair<int, int> PII;
typedef vector<PII> VP;
typedef vector<VP> VVP;

const int mod = 1e9 + 7;
const int maxn = 1e5 + 10;
ll fact[maxn];

ll inv(int x) {
	int e = mod-2;
	ll sol = 1;
	ll base = x;
	while (e) {
		if (e&1) sol = (sol * base)%mod;
		e >>= 1;
		base = (base * base)%mod;
	}
	return sol;
}

int main() {
	ios::sync_with_stdio(false);
	fact[0] = fact[1] = 1;
	for (int i = 2; i < maxn; ++i) fact[i] = (fact[i-1] * i)%mod;
	int n;
	cin >> n;
	VI A(n);
	for (auto& x : A) cin >> x;
	VI pos(n, 0);
	pos[0] = 1;
	int cur_pos = 1;
	for (int i = 1; i < n; ++i) {
		pos[i] = cur_pos;
		if (A[i] <= 2*(i-cur_pos+1)) cur_pos++;
	}
	int used = 0;
	ll sol = 1;
	for (int i = 1; i < n; ++i) {
		if (pos[i] != pos[i-1]) {
			sol = (sol * (i-used))%mod;
			++used;
		}
	}
	sol *= fact[n-used];
	sol %= mod;
	cout << sol;
}