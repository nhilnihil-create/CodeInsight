// ABC056B - NarrowRectanglesEasy

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ull;
typedef long long int ll;

int main() {
	int W, a, b;
	cin >> W >> a >> b;

	cout << max(0, abs(a - b) - W) << endl;

	return 0;
}
