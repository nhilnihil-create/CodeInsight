#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int mod = 1e9 + 7;

int main( ) {
	int n, b;
	long long ans;
	string s1, s2;
	cin >> n >> s1 >> s2;
	
	if (s1[0] == s2[0]) ans = 3;
	else ans = 6;
	for (int i = 0; i < n - 1; i++) {
		if (i < n - 1 && s1[i] == s1[i + 1]) continue;
		if (s1[i] == s2[i] && s2[i + 1] == s2[i + 1]) b = 2;
		if (s1[i] == s2[i] && s1[i + 1] != s2[i + 1]) b = 2;
		if (s1[i] != s2[i] && s1[i + 1] == s2[i + 1]) b = 1;
		if (s1[i] != s2[i] && s1[i + 1] != s2[i + 1]) b = 3;
		ans = (ans * b) % mod;
	}
	cout << ans << endl;
	
  	return 0;
}