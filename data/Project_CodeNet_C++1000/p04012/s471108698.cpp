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
	bool beautiful = true;
	for (int i = 0; i < p; i++) {
		if (num[i] % 2 != 0) beautiful = false;
	}
	if(beautiful) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}