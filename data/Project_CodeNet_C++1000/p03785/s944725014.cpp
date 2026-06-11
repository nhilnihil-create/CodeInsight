
// A - Airport Bus

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int T[100000];

int main() {
	int N, C, K;
	cin >> N >> C >> K;

	for (int i=0; i<N; i++) {
		cin >> T[i];
	}

	sort(T, T+N);

	queue<int> q;

	for (int i=0; i<N; i++) {
		q.push(T[i]);
	}

	int cnt = 0;
	while(! q.empty()) {
		cnt++;
		int c = 1;
		int t = q.front() + K;
		q.pop();

		while(! q.empty()) {
			if (c == C) break;
			if (q.front() > t) break;

			c++;
			q.pop();
		}
	}

	int ans = cnt;

	cout << ans << endl;

	return 0;
}