#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, M, a, b, c = 0;
	cin >> N >> M;
	vector<int> d(N);
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		d[a - 1]++;
		d[b - 1]--;
	}
	bool ans = true;
	for (int& i : d) {
		c += i;
		if (c % 2) {
			ans = false;
			break;
		}
	}
	if (ans) cout << "YES";
	else cout << "NO";
}