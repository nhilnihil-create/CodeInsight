#include <bits/stdc++.h>
#define eb emplace_back
#define sz(V) ((int)(V).size())
using namespace std;
typedef long long ll;
void fuk() { puts("NO"); exit(0); }

const int MAXN = 100055;

vector<int> G[MAXN];

ll A[MAXN];

int N;

ll f(int i, int p) {
	if(1 == sz(G[i])) return A[i];
	ll sum = 0, mx = 0;
	for(int v : G[i]) if(v != p) {
		ll t = f(v, i);
		sum += t;
		if(mx < t) mx = t;
	}
	ll ret = ll(A[i])*2 - sum;
	if(ret < 0) fuk();
	ll mt = sum - ret;
	if(mt < 0 || (mt&1)) fuk();
	mt >>= 1;
	if(min(sum >> 1, sum - mx) < mt) fuk();
	return ret;
}

int main() {
	ios::sync_with_stdio(false);

	cin >> N;
	for(int i = 1; i <= N; i++) cin >> A[i];
	if(2 == N) {
		puts(A[1] == A[2] ? "YES" : "NO");
		return 0;
	}
	for(int i = 1, a, b; i < N; i++) {
		cin >> a >> b;
		G[a].eb(b);
		G[b].eb(a);
	}
	for(int i = 1; i <= N; i++) if(1 < sz(G[i])) {
		if(f(i, -1)) fuk();
		break;
	}
	puts("YES");
	return 0;
}