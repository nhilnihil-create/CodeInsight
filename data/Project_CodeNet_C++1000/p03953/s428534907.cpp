#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

typedef long long ll;

const ll MAX_N = 1e5 + 5, MAX_LOG_N = 20;
ll n, S, E, prv, M, K;
ll Arr[MAX_N];
ll Brr[MAX_N];
ll nxt[MAX_LOG_N][MAX_N];
ll Crr[MAX_N];
bool mark[MAX_N];
vector <ll> p;

void dfs (ll v) {
	p.push_back(v);
	mark[v] = true;
	if (!mark[nxt[0][v]])
		dfs(nxt[0][v]);
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> S; prv = S;
	n--;
	for (ll i = 0; i < n; i++) {
		ll tmp;
		cin >> tmp;
		Arr[i] = tmp - prv;
		prv = tmp;
	}

	cin >> M >> K;
	for (ll i = 0; i < n; i++)
		Brr[i] = i;

	for (ll i = 0; i < M; i++) {
		ll tmp;
		cin >> tmp;
		tmp -= 2;

		swap(Brr[tmp], Brr[tmp + 1]);
	}

	for (ll i = 0; i < n; i++) {
		nxt[0][Brr[i]] = i;
	}

	for (ll i = 1; i < MAX_LOG_N; i++)
		for (ll j = 0; j < n; j++)
			nxt[i][j] = nxt[i - 1][nxt[i - 1][j]];

	for (ll i = 0; i < n; i++) {
		if (!mark[i]) {
			dfs(i);
			ll tmp = K % p.size();
			for (ll v: p) {
				ll u = v;
				for (ll i = MAX_LOG_N; ~i; i--)
					if ((tmp >> i) & 1)
						u = nxt[i][u];

				Crr[u] = Arr[v];
			}
			p.clear();
		}
	}

	cout << S << " ";
	for (ll i = 0; i < n; i++) {
		S += Crr[i];
		cout << S << " ";
	}
	return 0;
}