#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
int mod = 1e9 + 7;

int main() {
	string s;
	cin >> s;
	int n = (int)s.size();
	for (int i = n - 1; i >= 0; --i) {
		if ((i + 1) % 2 == 0) {
			bool d = 1;
			string p = "";
			for (int j = 0; j < i / 2; ++j) {
				if (s[j] != s[(i / 2) + j]) {
					d = 0;
					break;
				}
				p += s[j];
			}
			if (d) {
				//cout << p << " ";
				cout << i - 1;
				return 0;
			}
		}
	}
	cout << 0;
}

















