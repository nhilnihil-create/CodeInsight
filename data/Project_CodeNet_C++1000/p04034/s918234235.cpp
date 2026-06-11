
// B - Box and Ball

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int x[100000];
int y[100000];
int b[100000];
bool p[100000];

int main() {
	int N, M;
	cin >> N >> M;

	for (int i=0; i<M; i++) {
		cin >> x[i] >> y[i];
		x[i]--;
		y[i]--;
	}

	for (int i=0; i<N; i++) {
		b[i] = 1;
	}

	p[0] = true;

	for (int i=0; i<M; i++) {
		b[x[i]]--;
		b[y[i]]++;

		if (p[x[i]]) {
			p[y[i]] = true;
			if (b[x[i]] == 0) p[x[i]] = false;
		}
	}

	int ans = 0;
	for (int i=0; i<N; i++) {
		if (p[i]) ans++;
	}

	cout << ans << endl;

	return 0;
}