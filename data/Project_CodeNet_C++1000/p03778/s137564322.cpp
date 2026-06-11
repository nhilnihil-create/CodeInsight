#include <bits/stdc++.h>
using namespace std;

int main() {
	int W, A, B;
	cin >> W >> A >> B;
	if (A + W < B) {
		cout << abs(B - A - W) << endl;
	}
	else if (A <= B && B <= A + W) {
		cout << 0 << endl;
	}
	else if (A <= B + W && B <= A) {
		cout << 0 << endl;
	}
	else {
		cout << abs(B + W - A) << endl;
	}
}
