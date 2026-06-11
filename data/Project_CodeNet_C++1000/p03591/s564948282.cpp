#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(int argc, char **argv) {
	string s;
	cin >> s;
	bool ok = s.substr(0, 4) == "YAKI";
	cout << (ok ? "Yes" : "No") << endl;
}
