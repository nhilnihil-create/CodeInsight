#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (i % 2 == 0)cout << s.at(i);
	}
	cout << endl;
}