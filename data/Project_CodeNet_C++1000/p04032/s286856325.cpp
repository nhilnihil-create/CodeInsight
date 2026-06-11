// ABC043D - アンバランス

#include <bits/stdc++.h>
using namespace std;

int main() {
	string S;
	cin >> S;

	if (S[0] == S[1]) {
		cout << "1 2" << endl;
		return 0;
	}

	for (int i = 2; i < S.size(); i++) {
		if (S[i - 2] == S[i - 1]) {
			cout << i - 1 << " " << i << endl;
			return 0;
		}
		if (S[i - 2] == S[i]) {
			cout << i - 1 << " " << i + 1 << endl;
			return 0;
		}
	}

	cout << "-1 -1" << endl;
	return 0;
}
