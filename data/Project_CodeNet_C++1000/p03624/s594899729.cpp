#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	string S;
	cin >> S;
	int a[26] = { 0 };
	for (int i = 0; i < S.length(); i++) {
		a[S[i] - 97]++;
	}
	int re = 0;
	for (int i = 0; i < 26; i++) {
		if (a[i] == 0) {
			cout << (char)('a' + i) << endl;
			re++;
			break;
		}
	}
	if (re == 0) {
		cout << "None" << endl;
	}
	return 0;
}