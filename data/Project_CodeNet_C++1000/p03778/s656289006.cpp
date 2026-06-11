// ABC056B - 

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ull;
typedef long long int ll;

int main() {
	int W, a, b;
	cin >> W >> a >> b;

	if (a <= b) {
		if (b <= a + W) {
			cout << 0 << endl;
		} else {
			cout << b - (a + W) << endl;
		}
	} else if (b <= a) {
		if(a <= b + W) {
			cout << 0 << endl;
		} else {
			cout << a - (b + W) << endl;
		}
	}

	return 0;
}
