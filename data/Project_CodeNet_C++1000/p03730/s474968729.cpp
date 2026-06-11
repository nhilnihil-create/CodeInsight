#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 5LL << 60;
const ll mod = 1e9 + 7;

int main() {
	int A, B, C;
	cin >> A >> B >> C;
	for(int i = 1; i < 1e5; i++) {
		if(A * i % B == C) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	return 0;
}
