#include<iostream>

using namespace std;

int main() {
	int A, B, C, D;
	cin >> A >> B >> C >> D;

	int start = 0;
	int end = 0;

	if (A >= C) {
		start = A;
	}
	else if (A < C) {
		start = C;
	}

	if (B <= D) {
		end = B;
	}
	else if (B > D) {
		end = D;
	}

	if (end - start > 0) {
		cout << end - start << endl;
	}
	else {
		cout << 0 << endl;
	}
}
	
