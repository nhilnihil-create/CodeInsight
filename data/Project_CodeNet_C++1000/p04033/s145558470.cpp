#include <bits/stdc++.h>
using namespace std;
int main() {
	int a, b;
	cin >> a >> b;
	if (b <= -1) {
		if ((b - a + 1) % 2 == 0) {
			cout << "Positive" << endl;
		}
		else cout << "Negative" << endl;
	}
	else if (a >= 1) cout << "Positive" << endl;
	else cout << "Zero" << endl;
}