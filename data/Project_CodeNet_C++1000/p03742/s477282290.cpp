#include <bits/stdc++.h>
using namespace std;

int main() {
	long long x, y;
	cin >> x >> y;
	if (x > y) swap(x, y);
	puts(abs(x - y) < 2 ? "Brown" : "Alice");
	return 0;
}
