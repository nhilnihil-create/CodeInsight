#include "bits/stdc++.h"
using namespace std;

int main() {
	int A, B;
	cin >> A >> B;
	if (A == 1) {
		A += 13;
	}
	if (B == 1) {
		B += 13;
	}
	string ans = "Draw";
	if (A > B) {
		ans = "Alice";
	}
	else if (B > A) {
		ans = "Bob";
	}
	cout << ans << endl;
	return 0;
}