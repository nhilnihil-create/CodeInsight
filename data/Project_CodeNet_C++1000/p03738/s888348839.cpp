#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <iomanip>
#include <cmath>
using namespace std;
using ll = long long;
#define rep(i, j, n) for(size_t i = (j); i < (n); ++i)
#define rrep(i, j, n) for(size_t i = (n) - 1; (j) <= i; --i)
constexpr ll MOD = 1000000007;
constexpr ll INF = 1LL << 60;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(false);
	
	string a, b;
	cin >> a >> b;
	int n = a.size();
	int m = b.size();
	if (n > m) cout << "GREATER" << endl;
	else if (n < m) cout << "LESS" << endl;
	else {
		rep(i, 0, n) {
			if (a[i] < b[i]) {
				cout << "LESS" << endl;
				return 0;
			}
			else if (a[i] > b[i]) {
				cout << "GREATER" << endl;
				return 0;
			}

		}
		cout << "EQUAL" << endl;
	}
	return 0;

}
