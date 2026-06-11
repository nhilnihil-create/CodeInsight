#include <bits/stdc++.h>
using namespace std;


int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;

	if ((a<=c) && (c<=b) ) {
		if (d<=b) cout << d-c << endl;
		else cout << b-c << endl;
	}
	else if ((a<=d) && (d<=b)) {
		cout << d-a << endl;
	}
	else {
		if ((c<a) && (b<d)) cout << b-a << endl;
		else cout << 0 << endl;
	}

}
