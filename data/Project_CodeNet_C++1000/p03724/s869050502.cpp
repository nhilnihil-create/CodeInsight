
// B - Unplanned Queries

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int cnt[100000];

int main() {
	int N, M;
	cin >> N >> M;

	for (int i=0; i<M; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		cnt[a]++;
		cnt[b]++;
	}

	bool valid = true;
	for (int i=0; i<N; i++) {
		if (cnt[i] % 2 == 1) valid = false;
	}

	string ans;
	if (valid) ans = "YES";
	else ans = "NO";

	cout << ans << endl;

	return 0;
}