#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
	int a, b, h;
	cin >> a >> b >> h;
	if (!(h % 2 == 0)) return 0;
	cout << (((a + b) * h) / 2) << endl;

	return 0;
}
