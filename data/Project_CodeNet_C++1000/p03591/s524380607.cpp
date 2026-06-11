#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	string s;
	cin >> s;
	if (s.length() <= 3) {
		cout << "No" << endl;
		return 0;
	}
	s = s.substr(0, 4);
	if (s == "YAKI")cout << "Yes" << endl;
	else cout << "No" << endl;

}