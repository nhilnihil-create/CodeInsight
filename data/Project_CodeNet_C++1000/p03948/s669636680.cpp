#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <numeric>
#include <regex>
#include <tuple>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
#define modulo 1000000007 // 10^9 + 7
#define INF 1000000000 // 10^9
#define LLINF 1LL<<60

// 未完

int A[100001];
int m[100001]; // m[i] : A[0]～A[i]の最小値

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N, T; cin >> N >> T;
	cin >> A[0];
	m[0] = A[0];
	int dif = 0;
	for (int i = 1; i < N; i++) {
		cin >> A[i];
		m[i] = min(m[i - 1], A[i]);
		dif = max(dif, A[i] - m[i]);
	}

	// 差がdifになる組み合わせがいくつあるか

	int ans = 0;
	for (int i = 0; i < N; i++) {
		if (A[i] - m[i] == dif) ans++;
	}

	cout << ans << endl;

	return 0;
}