
// B - fLIP

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int main() {
	int N, M, K;
	cin >> N >> M >> K;

	string ans = "No";
	for (int i=0; i<=N; i++) {
		for (int j=0; j<=M; j++) {
			int k = i * M + j * N - 2 * i * j;
			if (k == K) {
				ans = "Yes";
				break;
			}
		}
	}


	cout << ans << endl;

	return 0;
}