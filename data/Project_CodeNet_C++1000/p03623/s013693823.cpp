// ABC071A - 

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ull;
typedef long long int ll;

int main() {
	int x, a, b;
	cin >> x >> a >> b;

	if (abs(x - a) < abs(x - b)) {
		cout << 'A' << endl;
	} else {
		cout << 'B' << endl;
	}

	return 0;
}
