// ABC052B - 

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ull;
typedef long long int ll;

int main() {
	int A, B, C, D;
	cin >> A >> B >> C >> D;

	if (A * B >= C * D) {
		cout << A * B << endl;
	} else {
		cout << C * D << endl;
	}

	return 0;
}
