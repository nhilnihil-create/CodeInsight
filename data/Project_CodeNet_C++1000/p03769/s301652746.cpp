#pragma GCC target ("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma warning (disable:4996)
#include"bits/stdc++.h"
#define int long long
#define MRE assert(0);
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const long long mod = 1000000007;
const long long inf = 1e17;
typedef pair<int, int> P;
int in[200];
vector<int>G[200];

int popcnt(int a) {
	int res = 0;
	rep(i, 55) {
		if (a&(1ll << i))res++;
	}
	return res;
}

signed main() {
	vector<P>V;
	rep(i, 55) {
		V.push_back(P((1ll << i) - 1, i));
	}
	int n; cin >> n; int N = n;
	int cst = 0, flg = 0;
	for (int i = 54; i >= 0; i--) {
		if (n >= V[i].first) {
			n -= V[i].first;
			cst = V[i].second;
			break;
		}
	}
	int S = cst + popcnt(n);

	rep(i, S - 1) {
		G[i].push_back(i + 1);
		G[S + i].push_back(S + i + 1);
	}
	rep(i, cst) {
		G[i].push_back(S);
	}
	for (int i = 54; i >= 0; i--) {
		if (n >= (1ll << i)) {
			G[cst].push_back(cst + S - i);
			cst++;
			n -= (1ll << i);
		}
	}
	
	rep(i, 2 * S) {
		for (int e : G[i])in[e]++;
	}
	priority_queue<int>Q;
	rep(i, 2 * S)if (!in[i])Q.push(i);
	vector<int>V2;
	while (Q.size()) {
		int p = Q.top(); Q.pop();
		V2.push_back(p);
		for (int e : G[p]) {
			in[e]--;
			if (!in[e]) {
				Q.push(e);
			}
		}
	}
	rep(i, V2.size()) {
		V2[i] = V2[i] % S + 1;
	}
	cout << S + S << endl;
	rep(i, V2.size()) {
		if (i)cout << ' ';
		cout << V2[i];
	}cout << endl;
}