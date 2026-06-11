#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL -1
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	string O, E;
	cin >> O >> E;

	int len = O.size();
	string S;
	for (int i = 0; i < len; i++) {
		S += O.at(i);
		if (i < E.size()) S += E.at(i);
	}

	cout << S << endl;
}