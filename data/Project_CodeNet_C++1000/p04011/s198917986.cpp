#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
	int N, K, X, Y;
	cin >> N >> K >> X >> Y;

	int tl = 0;

	for (int i = 1; i <= N; i++) {
		if (i < K + 1) tl += X;
		else tl += Y;
	}

	cout << tl << endl;

	return 0;
}
