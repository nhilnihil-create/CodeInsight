#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 2e5 + 50;
const int mod = 1e9 + 7;

bool d[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int v, u;
		cin >> v >> u;
		d[v] ^= 1;
		d[u] ^= 1;
	}
	for (int i = 1; i <= n; i++)
		if (d[i])
			return cout << "NO\n", 0;
	cout << "YES\n";
}
