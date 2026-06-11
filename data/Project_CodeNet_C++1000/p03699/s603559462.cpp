
// C - Bugged

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;


int s[100];

int main() {
	int N;
	cin >> N;

	int score = 0;
	for (int i=0; i<N; i++) {
		cin >> s[i];
		score += s[i];
	}

	if (score % 10 != 0) {
		cout << score << endl;
		return 0;
	}

	sort(s, s+N);

	bool no_valid = true;
	for (int i=0; i<N; i++) {
		if (s[i] % 10 != 0) {
			score -= s[i];
			no_valid = false;
			break;
		}
	}

	if (no_valid) {
		cout << 0 << endl;
	} else {
		cout << score << endl;
	}

	return 0;
}