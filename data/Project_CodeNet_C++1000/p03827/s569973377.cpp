#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N;
	cin >> N;
	string S;
	cin >> S;
	int x = 0, mx = 0;
	for (int i = 0; i < N; ++i) {
		if (S[i] == 'I') {
			++x;
		} else {
			--x;
		}
		mx = max(mx, x);
	}
	cout << mx << '\n';
	
	return 0;
}
