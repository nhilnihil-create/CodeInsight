#include <iostream>
using namespace std;
#define rep(i, j, n) for(int i = (j); i < (n); ++i)

int main() {
	string s, t;
	int n; cin >> n >> s >> t;

	rep(i, 0, n + 1) {
		bool ok = true;
		rep(j, 0, n - i) {
			if (s[i + j] != t[j]) ok = false;
		}
		if (ok) {
			cout << i + n << endl;
			return 0;
		}
	}
	return 0;
}