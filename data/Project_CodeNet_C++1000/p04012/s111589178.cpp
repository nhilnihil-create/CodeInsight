#include <bits/stdc++.h>
using namespace std;

int main() {
	string w;

	cin >> w;
	vector<int> hash(26);
	int n = w.length();

	for (int i=0; i<n; i++) {
		hash[w[i]-'a']++;
	}

	bool flag = true;
	for (int i=0; i<26; i++) {
		if (hash[i]%2 == 1) {
			flag = false;
			break;
		}
	}
	if (flag)
		cout << "Yes";
	else
		cout << "No";
}