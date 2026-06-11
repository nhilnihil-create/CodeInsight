#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string s;
int n;

int main() {
	cin >> s;
	n = s.size();
	for (int i = 0; i < n - 1; ++i)
		for (int j = i + 1; j < i + 3 && j < n; ++j)
			if (s[j] == s[i]) {
				cout << i + 1 << ' ' << j + 1 << endl;
				return 0;
			}
	cout << "-1 -1" << endl;
}
