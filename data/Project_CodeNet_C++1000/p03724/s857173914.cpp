#include <bits/stdc++.h>

using namespace std;

int D[101010];
int n, q, s;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int i, u, v;

	cin >> n >> q;

	for(; q --; ){
		cin >> u >> v;
		D[u] ++; D[v] ++;
	}

	for(i = 1; i <= n; i ++){
		s |= D[i];
	}

	cout << (s & 1? "NO" : "YES");

	return 0;
}