#include "bits/stdc++.h"
using namespace std;

int main() {
	int N;
	cin >> N;
	int x = N % 10;
	int y = N / 10;
	if (x == 9 || y == 9) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}
