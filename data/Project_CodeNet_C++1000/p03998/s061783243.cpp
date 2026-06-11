#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int main() {
	string a[3];
	int pos[3] = {0};
	cin >> a[0] >> a[1] >> a[2];
	int ind = 0;
	while (pos[ind] != a[ind].size()) {
		char c = a[ind][ pos[ind] ];
		pos[ind] ++;
		ind = c - 'a';
	}
	char ans = ind + 'a';
	ans = toupper(ans);
	cout << ans << endl;
	return 0;
}