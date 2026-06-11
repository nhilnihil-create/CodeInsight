#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL -1
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int N;
	cin >> N;

	int n = 1;
	while (1) {
		if (n * 2 > N) break;
		else n *= 2;
	}

	cout << n << endl;
}