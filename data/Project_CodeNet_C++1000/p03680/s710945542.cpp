#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pint = pair<int, int>;

int main() {
	int N;
	cin >> N;
	vector<int> a(N);
	vector<bool> visit(N, false);
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
	}

	int cur = a[0];
	int cnt = 1;
	visit[0] = true;
	for (; cnt <= N; ++cnt) {
		if (visit[cur-1]) {
			cnt = -1;
			break;
		}
		if (cur == 2) {
			break;
		}
		visit[cur - 1] = true;
		cur = a[cur - 1];
	}
	cout << cnt << endl;

	return 0;
}
