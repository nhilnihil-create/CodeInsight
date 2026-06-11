#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL -1
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int N;
	cin >> N;
	
	int64_t p = 1;
	for (int i = 1; i <= N; i++) {
		p = p % MOD * i % MOD;
	}

	cout << p << endl;
}