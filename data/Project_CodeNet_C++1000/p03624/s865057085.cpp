#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	string s; cin >> s;
	const int p = 26;
	vector<int> num(p, 0);
	for (int i = 0; i < s.size(); i++) {
		num[s[i] - 'a'] = 1;
	}
	int index = -1;
	for (int i = 0; i < p; i++) {
		if (num[i] == 0) {
			index = i;
			break;
		}
	}
	if (index == -1) cout << "None" << endl;
	else cout << (char)(index + 'a') << endl;
	return 0;
}