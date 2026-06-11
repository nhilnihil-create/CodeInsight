#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL -1
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	string s;
	cin >> s;

	int n = s.size() - 2;
	cout << s.at(0) << n << s.at(n + 1) << endl;
}