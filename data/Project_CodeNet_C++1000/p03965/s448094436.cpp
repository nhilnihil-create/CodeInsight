#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
	cin >> s;
	int n = s.size(), p = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'p')
			p++;
	}
	cout << (n - p * 2) / 2 << endl;
}
