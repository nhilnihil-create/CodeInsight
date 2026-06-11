#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n; cin >> n;
	string s; cin >> s;
	int ans = -1000000;
	int point = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'I') point++;
		if (s[i] == 'D') point--;
		ans = max(ans, point);
	}

	cout << max(0, ans) << endl;
	return 0;
}