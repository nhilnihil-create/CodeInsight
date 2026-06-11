
// D - Coloring Dominoes

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
const ll MOD = 1e9 + 7;

int N;
string S1, S2;

char dir(int i) {
	if (S1[i] == S2[i]) return 'v';
	else return 'h';
}

int main() {
	cin >> N >> S1 >> S2;

	ll ans;
	char prev_dir;
	int i;

	if (dir(0) == 'v') {
		ans = 3;
		prev_dir = 'v';
		i = 1;
	} else {
		ans = 6;
		prev_dir = 'h';
		i = 2;
	}

	while(i < S1.size()) {
		if (prev_dir == 'v' && dir(i) == 'v') {
			ans = (ans * 2) % MOD;
			prev_dir = 'v';
			i += 1;
		} else if (prev_dir == 'v' && dir(i) == 'h') {
			ans = (ans * 2) % MOD;
			prev_dir = 'h';
			i += 2;
		} else if (prev_dir == 'h' && dir(i) == 'v') {
			ans = ans;
			prev_dir = 'v';
			i += 1;
		} else {
			ans = (ans * 3) % MOD;
			prev_dir = 'h';
			i += 2;
		}
	}

	cout << ans << endl;

	return 0;
}