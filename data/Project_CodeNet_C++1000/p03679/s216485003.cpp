#include"bits/stdc++.h"
using namespace std;

int main() {
	int X, A, B;
	cin >> X >> A >> B;
	string judge = "safe";
	if (A >= B) {
		judge = "delicious";
	}
	else if (A + X < B) {
		judge = "dangerous";
	}
	cout << judge << endl;
	return 0;
}