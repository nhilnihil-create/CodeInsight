#include"bits/stdc++.h"
using namespace std;

int main() {
	int A, B, C;
	cin >> A >> B >> C;
	string judge = "Yes";
	if (C < A || B < C) {
		judge = "No";
	}
	cout << judge << endl;
	return 0;
}