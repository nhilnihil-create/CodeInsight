
// C - Cat Snuke and a Voyage

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

bool to_I[200000];
bool to_N[200000];

int main() {
	int N, M;
	cin >> N >> M;

	int a, b;
	for (int i=0; i<M; i++) {
		cin >> a >> b;
		if (a == 1) to_I[b] = true;
		if (b == 1) to_I[a] = true;
		if (a == N) to_N[b] = true;
		if (b == N) to_N[a] = true;
	}

	string ans = "IMPOSSIBLE";
	for (int i=2; i<N; i++) {
		if (to_I[i] && to_N[i]) ans = "POSSIBLE";
	}

	cout << ans << endl;

	return 0;
}