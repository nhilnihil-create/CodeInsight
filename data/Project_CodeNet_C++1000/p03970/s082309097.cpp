#include<bits/stdc++.h>
using namespace std;
int ans;
string s,a = "CODEFESTIVAL2016";
int main() {
	ios::sync_with_stdio(false);
	cin >> s;
	for(int i = 0; i < s.size(); i++)
		ans += s[i] != a[i];
	cout << ans << endl;
	return 0;
}