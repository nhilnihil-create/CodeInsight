#include"bits/stdc++.h"
using namespace std;

int main() {
	int A, B;
	cin >> A >> B;
	A += B;
	if (A >= 24) {
		A -= 24;
	}
	cout << A << endl;
	return 0;
}