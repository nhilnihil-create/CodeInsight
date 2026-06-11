#include <bits/stdc++.h>
#define mod 1000000007
#define mod998 998244353
#define sp ' '
#define intmax 2147483647
#define llmax 9223372036854775807
#define mkp make_pair
typedef long long ll;
using namespace std; 

int M, a, b, t[100000], vis[100000], c[100000];
vector<int>v[100000];
ll res, A, B, C, N;

int T(int x) {
	if (t[x] < 0)return x;
	return t[x] = T(t[x]);
}

void U(int x, int y) {
	x = T(x);
	y = T(y);
	if (x != y) {
		if (t[x] < t[y]) {
			t[x] += t[y];
			t[y] = x;
		}
		else {
			t[y] += t[x];
			t[x] = y;
		}
	}
}

void dfs(int x, int t) {
	vis[x] = t;
	for (int i : v[x]) {
		if (!vis[i]) {
			dfs(i, (t & 1) + 1);
		}
	}
}

int main() {
	cin >> N >> M;
	memset(t, -1, sizeof t);
	for (int i = 0; i < M; ++i) {
		cin >> a >> b;
		--a;
		--b;
		v[a].push_back(b);
		v[b].push_back(a);
		U(a, b);
	}
	for (int i = 0; i < N; ++i) {
		if (!vis[i]) {
			dfs(i, 1);
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j : v[i]) {
			if (vis[i] == vis[j]) {
				c[T(i)] = 1;
			}
		}		
	}
	for (int i = 0; i < N; ++i) {
		if (t[i] < 0) {
			if (v[i].empty()) {
				++C;
			}
			else if (c[i]) {
				++A;
			}
			else {
				++B;
			}
		}
	}
	for (int i = 0; i < N; ++i) {
		if (t[i] < 0) {
			if (v[i].empty()) {
				res += N;
			}
			else if (c[i]) {
				res += A + B + C * -t[i];
			}
			else {
				res += A + B * 2 + C * -t[i];
			}
		}
	}
	cout << res << endl;
}