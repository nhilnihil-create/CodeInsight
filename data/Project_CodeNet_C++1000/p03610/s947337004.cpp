#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	string s;
	cin >> s;

	for (int ii = 0; ii < s.size(); ++ii){
		if (ii % 2 == 1) continue;
		cout << s[ii];
	}

	cout << "\n";

	return 0;
}
