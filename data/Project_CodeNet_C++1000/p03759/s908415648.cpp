// ABC058A - 

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ull;
typedef long long int ll;

int main() {
	int a, b, c;
	cin >> a >> b >> c;

	if (b - a == c - b) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}

	return 0;
}
