#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int left_count = 0;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		char x = s.at(i);
		if (x == '(')left_count++;
		else {
			if (left_count >= 1)left_count--;
			else ans++;
		}
	}
	for (int i = 0; i < ans; i++)cout << "(";
	cout << s;
	for (int i = 0; i < left_count; i++)cout << ")";
	cout << endl;
}
