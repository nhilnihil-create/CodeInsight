#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
int main() {
	LL X, Y;
	cin >> X >> Y;
	if (abs(X - Y) <= 1) {
		cout << "Brown" << endl;
	}
	else {
		cout << "Alice" << endl;
	}
}