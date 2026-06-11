#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"

using namespace std;

const long long int MOD = 1000000007;
const long long int INF = 1000000000000000200;

long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<long long int>v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	cin >> M >> K;
	vector<vector<pair<int, int>>>tap(N - 1, vector<pair<int, int>>(64));
	for (int i = 0; i < N - 1; i++) {
		tap[i][0].first = v[i + 1] - v[i];
		tap[i][0].second = i;
	}
	for (int i = 0; i < M; i++) {
		cin >> L;
		L -= 2;
		swap(tap[L][0], tap[L + 1][0]);
	}
	for (int j = 1; j < 64; j++) {
		for (int i = 0; i < N - 1; i++) {
			tap[i][j] = tap[tap[i][j - 1].second][j - 1];
		}
	}
	long long int ans = v[0];
	cout << ans << endl;
	for (int i = 0; i < N - 1; i++) {
		long long int fig = i;
		for (int j = 0; j < 64; j++) {
			if (K >> j & 1) {
				fig = tap[fig][j].second;
			}
		}
		ans += v[fig + 1] - v[fig];
		cout << ans << endl;
	}
	return 0;
}