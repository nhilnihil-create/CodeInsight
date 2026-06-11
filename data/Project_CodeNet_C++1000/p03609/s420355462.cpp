#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
	int x, t;
	cin >> x >> t;
	if (x - t >= 0) {
		cout << x - t << endl;
	}
	else if (x - t < 0) {
		cout << 0 << endl;
	} 
}