#include"bits/stdc++.h"
using namespace std;

int main() {
	string S;
	cin >> S;
	string s = S.substr(0, 4);
	cout << (s == "YAKI" ? "Yes" : "No") << endl;
	return 0;
}