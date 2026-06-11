#include <bits/stdc++.h>
#define mod 1000000007
#define mod998 998244353
#define sp ' '
#define intmax 2147483647
#define llmax 9223372036854775807
#define mkp make_pair
typedef long long ll;
using namespace std;

int N, A[100000], a, b;
vector<int>v[100000];
bool vis[100000], f;

ll dfs(int x) {
	vis[x] = true;
	if (x) {
		ll S = 0, MAX = -1;
		for (int i : v[x]) {
			if (!vis[i]) {
				ll k = dfs(i);
				S += k;
				MAX = max(MAX, k);
			}
		}
		if (MAX == -1) {
			return A[x];
		}
		ll t = 2 * A[x] - S;
		if (MAX > A[x] || t < 0 || S < A[x]) {
			f = false;
			return 0;
		}
		return t;
	}
	else {
		ll S = 0, MAX = -1;
		for (int i : v[x]) {
			if (!vis[i]) {
				ll k = dfs(i);
				S += k;
				MAX = max(MAX, k);
			}
		}
		if (v[x].size() == 1) {
			if (S != A[x]) {
				f = false;
			}
		}
		else {
			if (MAX > A[x] || (S & 1) || S / 2 != A[x]) {
				f = false;
			}
		}
		return 0;
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	for (int i = 1; i < N; ++i) {
		cin >> a >> b;
		--a;
		--b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	f = true;
	dfs(0);
	puts(f ? "YES" : "NO");
	return 0;
}