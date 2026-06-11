#include <bits/stdc++.h>
using namespace std;
int main() {
	int64_t x, a, b;
	cin >> x >> a >> b;
	if (a >= b) cout << "delicious" << endl;
	else if (a < b && b <= a + x)cout << "safe" << endl;
	else cout << "dangerous" << endl;
}