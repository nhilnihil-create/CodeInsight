#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;
using ll = long long;
#define rep(i, j, n) for(int i = (j); i < (n); ++i)
#define rrep(i, j, n) for(int i = (n) - 1; (j) <= i; --i)

constexpr ll MOD = 1000000007;
constexpr ll INF = 1LL << 60;

ll n, a, b;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n >> a >> b;

	if ((n == 1 && a != b) || a > b) {
		cout << 0 << endl;
		return 0;
	}
	cout << a + b * (n - 1) - (a * (n - 1) + b) + 1 << endl;
	return 0;
}