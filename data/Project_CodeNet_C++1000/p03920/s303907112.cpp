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
#define MOD 1000000007 // 10^9 + 7
#define INF 1000000000 // 10^9
#define LLINF 1LL<<60


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N; cin >> N;
	int ans = 1;
	while (ans*(ans + 1) / 2 < N) ans++;
	while (N > 0) {
		if (N >= ans) {
			cout << ans << endl;
			N -= ans;
		}
		ans--;
	}

	return 0;
}