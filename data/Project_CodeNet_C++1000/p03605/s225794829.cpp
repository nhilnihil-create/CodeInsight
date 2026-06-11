#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	string s; cin >> s;
	string ans;
	if (s[0] == '9' || s[1] == '9') ans = "Yes";
	else ans = "No";	
	cout << ans << endl;
	return 0;
}