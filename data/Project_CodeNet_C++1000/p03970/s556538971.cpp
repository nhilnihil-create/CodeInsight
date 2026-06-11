#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
	int cnt = 0;
	string s1, s2 = "CODEFESTIVAL2016";
	cin >> s1;
	for (int i = 0; i < 16; i++) {
		if (s1.substr(i, 1) != s2.substr(i, 1))
			cnt++;
	}
	cout << cnt << endl;

	return 0;
}

