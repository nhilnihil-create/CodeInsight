#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
using ll = long long;
#define repl(i, l, r) for (int i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
int main() {
	int n;
	string s, t;
	cin >> n >> s >> t;
	rep(i, n) {
		int now = 0;
		rep(j, n - i) {
			if (s[i + j] == t[j]) now++;
		}
		if (now == n - i) {
			cout << n + i << endl;
			return 0;
		}
	}
	cout << 2 * n << endl;
	return 0;
}