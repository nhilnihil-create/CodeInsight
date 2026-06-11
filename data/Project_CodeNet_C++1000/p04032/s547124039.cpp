#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;


int main() {
	string s;
	cin >> s;
	int k = 3;
	int n = (int)s.length();

	vector<int> counter(26, 0);

	for (int i = 0; i < n; i++) {
		counter[s[i] - 'a']++;
		if (i - k + 1 >= 0) {
			int total = 0;
			for (int i = 0; i < 26; i++) {
				if (counter[i] != 0) total++;
			}
			if (total <= 2) {
				cout << i - k + 2 << " " << i + 1;
				return 0;
			}
			counter[s[i - k + 1] - 'a']--;
		}
	}

	int total = 0;

	for (int i = 0; i < 26; i++) {
		if (counter[i] != 0) total++;
	}

	if (total <= 1) {
		cout << 1 << " " << 2;
		return 0;
	}

	cout << -1 << " " << -1 << endl;
}
