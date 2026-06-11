// ABC070B - 

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ull;
typedef long long int ll;

int main() {
	int A, B, C, D;
	cin >> A >> B >> C >> D;

	if (A >= C) {
		if (D < A) {
			cout << 0 << endl;
		} else {
			cout << min(B, D) - A << endl;
		}
	} else {
		if (B < C) {
			cout << 0 << endl;
		} else {
			cout << min(B, D) - C << endl;
		}
	}

	return 0;
}
