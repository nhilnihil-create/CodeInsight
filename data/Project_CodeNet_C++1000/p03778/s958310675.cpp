#include "bits/stdc++.h"
using namespace std;

int main() {
	int W, A, B;
	cin >> W >> A >> B;
	if ((A + W) < B) {
		cout <<  B - A - W << endl;
	}
	else if (A > (B + W)) {
		cout << A - B - W << endl;
	}
	else {
		cout << 0 << endl;
	}
	return 0;
}