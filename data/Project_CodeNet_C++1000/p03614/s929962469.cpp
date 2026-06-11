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

int p[100001];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N; cin >> N;
	for (int i = 1; i <= N; i++) cin >> p[i];

	int ans = 0;
	for (int i = 1; i <= N - 1; i++) {
		if (p[i] == i) {
			int tmp = p[i];
			p[i] = p[i + 1];
			p[i + 1] = tmp;
			ans++;
		}
	}
	if (p[N] == N) {
		ans++;
	}

	cout << ans << endl;

	return 0;
}