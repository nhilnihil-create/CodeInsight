#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> P;
const LL MOD = 1000000007LL;

int main() {
	LL K;
	cin >> K;
	int r = K % 50;
	cout << 50 << endl;
	for (int i = 0; i < 50; i++) {
		LL a = i + K / 50;
		if (i < r) a += 50 - (r - 1);
		else a -= r;
		if (i > 0) cout << " ";
		cout << a;
	}
	cout << endl;
}