#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	string s, t;
	cin >> N >> s >> t;
	int i = N;
	while (s.substr(N-i, i) != t.substr(0,i)) {
		i--;
	}
	cout << 2 * N - i << endl;
	return 0;
}
