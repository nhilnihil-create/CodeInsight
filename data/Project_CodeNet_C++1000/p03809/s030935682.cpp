#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

const int MN = 100010;

int N;
vi g[MN];
int A[MN];

ll dfs(int v, int p)
{
	bool leaf = 1;
	ll sum = 0;
	ll maxi = 0;

	for (int to : g[v]) if (to != p) {
		ll t = dfs(to, v);
		if (t == -1) return -1;
		maxi = max(maxi, t);
		sum += t;
		leaf = 0;
	}

	if (leaf) {
		return A[v];
	} else {
		ll res = A[v] * 2 - sum;
		if (res < 0 || (p == -1 && res != 0)) return -1;
		maxi = max(maxi, res);
		if (maxi > A[v]) {
			return -1;
		} else {
			return res;
		}
	}
}

int main() {
	cin >> N;
	rep(i, N) cin >> A[i];

	rep(i, N-1) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		g[a].pb(b);
		g[b].pb(a);
	}

	if (N == 2) {
		puts(A[0] != A[1] ? "NO" : "YES");
		return 0;
	}

	int r = -1;
	rep(i, N) if (g[i].size() > 1) {
		r = i;
	}

	puts(dfs(r, -1) == -1 ? "NO" : "YES");
	return 0;
}