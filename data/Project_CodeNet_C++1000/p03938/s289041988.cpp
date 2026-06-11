#include <iostream>
#include <vector>
using namespace std;
#define rep(i, j, n) for(size_t i = (j); i < (n); ++i)
int main() {
	int n, p; cin >> n;

	vector<int> target(n + 1);
	rep(i, 1, n + 1) {
		cin >> p;
		target[p] = i;
	}
	rep(i, 1, n + 1) cout << n * i << " \n"[i == n];
	rep(i, 1, n + 1) cout << n * (n - i) + target[i] << " \n"[i == n];
	return 0;
}
