#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL -1
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	string S;
	cin >> S;

	S.pop_back();
	//cout << S << endl;

	while (S.size()) {
		if (S.size() % 2) {
			S.pop_back();
		}
		else {
			string a, b;
			a = S.substr(0, S.size() / 2);
			b = S.substr(S.size() / 2);

			if (a == b) break;
			else S.pop_back();
		}
	}

	cout << S.size() << endl;
}