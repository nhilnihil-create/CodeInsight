#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<vector<int>> Graph;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
#define pi 3.14159265359
#define inf 2147483647
#define INF 9223372036854775807
#define mod 1000000007
#define mod2 998244353

int main() {
	int N; cin >> N;
	vector<int> T(N);
	ll sum = 0;
	for(int i = 0; i < N; i++) {
		cin >> T[i];
		sum += T[i];
	}
	int M; cin >> M;
	vector<int> P(M), X(M);
	for(int i = 0; i < M; i++) cin >> P[i] >> X[i];
	for(int i = 0; i < M; i++) {
		ll ans = sum - T[P[i] - 1] + X[i];
		cout << ans << endl;
	}
	return 0;
}