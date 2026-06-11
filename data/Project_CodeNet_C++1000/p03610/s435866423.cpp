#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL -1
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	string s;
	cin >> s;

	for (int i = 0; i < s.size(); i += 2) {
		cout << s.at(i);
	}
	cout << endl;
}