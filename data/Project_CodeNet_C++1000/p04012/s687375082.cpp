#include<cstdio>
#include<iostream>
using namespace std;

int main(void) {
	string w;
	cin >> w;
	int c[26] = {0};
	for (int i = 0; i < w.length(); i++) {
		c[w[i] - 'a']++;
	}
	string ans = "Yes";
	for (int i = 0; i < 26; i++) {
		if (c[i] % 2 != 0) ans = "No";
	}
	cout << ans << "\n";
	return 0;
}
