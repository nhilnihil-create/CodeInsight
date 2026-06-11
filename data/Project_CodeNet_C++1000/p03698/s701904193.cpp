#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	string s; cin >> s;
	const int p = 26;
	vector<int> num(p, 0);
	for (int i = 0; i < s.size(); i++) {
		num[s[i] - 'a']++;
	}
	bool allDifferent = true;
	for (int i = 0; i < p; i++) {
		if (2 <= num[i]) allDifferent = false;
	}
	if (allDifferent) cout << "yes" << endl;
	else cout << "no" << endl;
	return 0;
}