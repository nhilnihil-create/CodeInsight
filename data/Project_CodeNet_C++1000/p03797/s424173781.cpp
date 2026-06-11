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
	ll N, M; cin >> N >> M;
	ll Scc;
	if(2 * N >= M) {
		Scc = M / 2;
	}
	else if(N < 2 * M) {
		Scc = N;
		M -= 2 * N;
		Scc += M / 4;
	}
	cout << Scc << endl;
	return 0;
}