#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int x, y;
	scanf("%d %d", &x, &y);

	bool is_positive;
	if (abs(y) - abs(x) > 0) {
		is_positive = true;
	} else {
		is_positive = false;
	}

	int count = 0;
	if ((x > 0 != is_positive) && x != 0) {
		count++;
	}
	if ((y > 0 != is_positive) && y != 0) {
		count++;
	}
	printf("%d", count + abs(abs(y) - abs(x)));
	return 0;
}