#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main() {
	int N = 0, W = 0, S = 0, E = 0;
	string s;
	cin >> s;

	rep(i, s.size()) {
		if (s[i] == 'N') N++;
		else if (s[i] == 'W') W++;
		else if (s[i] == 'S') S++;
		else if (s[i] == 'E') E++;
	}

	if ((N + S == 0 || N >= 1 && S >= 1) && (W + E == 0 || W >= 1 && E >= 1))
		cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}