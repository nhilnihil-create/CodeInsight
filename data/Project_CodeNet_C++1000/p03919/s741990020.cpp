#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <iomanip>
#include <queue>
#include <stack>
#include <deque>
#include <utility>
#include <functional>
#define rep(i,n) for(int i=0;i<n;++i)
#define FOR(i,s) for(int i=s;i>=0;--i)

using ll = long long;
using namespace std;

const ll INF = 1010101010;
const ll MOD = 1000000007;

ll n, m, ans = 0; string A[101][101];
int main() {
	cin >> n >> m;
	rep(i, n) rep(j, m) cin >> A[i][j];
	rep(i, n) rep(j, m) {
		if (A[i][j] == "snuke") {
			char c = 'A' + j;
			cout << c << i + 1 << endl;
			return 0;
		}
	}
	return 0;
}