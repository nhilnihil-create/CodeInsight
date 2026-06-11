#pragma GCC optimize("Ofast", "unroll-loops")

#include <bits/stdc++.h>

using namespace std;

int N, M, K;

void input(void) {
	cin >> N >> M >> K;
}

bool judge(int x, int y) {
	return (N * x + M * y - 2 * x * y == K);
}

int main(void) {
	input();
	bool res = false;
	for (int x = 0; x <= M; ++x)
		for (int y = 0; y <= N; ++y)
			res |= judge(x, y);
	cout << (res ? "Yes" : "No") << endl;
	return 0;
}