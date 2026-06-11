#include <bits/stdc++.h>
#define PI 3.14159265359
using namespace std;

int main() {
	string s;
	cin >> s;

	int sl = s.size();
	int ac, zc;
	ac = -1;
	zc = -1;
	for (int i = 0; i < sl; i++) {
		if (s.at(i) == 'A') {
			if (ac == -1) ac = i;
		}
		if (s.at(i) == 'Z') {
			zc = i;
		}
	}

	cout << zc - ac + 1 << endl;
}