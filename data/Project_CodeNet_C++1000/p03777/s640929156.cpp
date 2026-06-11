// ABC056A - 

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ull;
typedef long long int ll;

int main() {
	char a, b;
	cin >> a >> b;

	if ((a == 'H')&&(b == 'H')) {
		cout << 'H' << endl;
	} else if ((a == 'H')&&(b == 'D')) {
		cout << 'D' << endl;
	} else if ((a == 'D')&&(b == 'H')) {
		cout << 'D' << endl;
	} else if ((a == 'D')&&(b == 'D')) {
		cout << 'H' << endl;
	} else {
	}

	return 0;
}
