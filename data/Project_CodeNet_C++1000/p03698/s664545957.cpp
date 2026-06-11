#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL -1
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	string S;
	cin >> S;

	vector<bool> v(26);
	for (int i = 0; i < S.size(); i++) {
		int n = (int)S.at(i) - 97;

		if (v.at(n)) {
			cout << "no" << endl;
			return 0;
		}
		else {
			v.at(n) = true;
		}
	}

	cout << "yes" << endl;
}