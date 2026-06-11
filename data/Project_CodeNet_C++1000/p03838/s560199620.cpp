#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <iomanip>
using namespace std;
using ll = long long;
#define rep(i, j, n) for(int i = (j); i < (n); ++i)
#define rrep(i, j, n) for(int i = (n) - 1; (j) <= i; --i)
constexpr ll MOD = 1000000007;
constexpr ll INF = 1LL << 60;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(false);
	ll x, y;
	cin >> x >> y;
	ll unko = INF;
	if (x <= y) unko = min(unko, y - x);
	if (-x <= y) unko = min(unko, x + y + 1);
	if (x <= -y) unko = min(unko, -x - y + 1);
	if (-x <= -y) unko = min(unko, x - y + 2);
	cout << unko;
	return 0;
}
