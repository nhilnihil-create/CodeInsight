#include<bits/stdc++.h>
#include <array>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); i++)
using LL = long long;
using ULL = unsigned long long;


void solve() {
	int n; cin >> n;
	int pp[40000]; rep(i, n) { int p; cin >> p; pp[p-1] = i; }
	for (int i = 0; i < n; i++) {
		if (i != 0) cout << " ";
		cout << n * i + pp[i] + 1;
	}cout << endl;
	for (int i = 0; i < n; i++) {
		if (i != 0) cout << " ";
		cout << n * (n - i);
	}cout << endl;
}

int main() {

	solve();

	return 0;
}
