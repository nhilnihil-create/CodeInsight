// ABC054A - 

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ull;
typedef long long int ll;

int main() {
	int A, B;
	cin >> A >> B;

	if (A == 1) {
		A = 14;
	}
	if (B == 1) {
		B = 14;
	}

	if (A > B) {
		cout << "Alice" << endl;
	} else if (A < B) {
		cout << "Bob" << endl;
	} else {
		cout << "Draw" << endl;
	}

	return 0;
}
