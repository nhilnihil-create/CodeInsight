#include <bits/stdc++.h>

using namespace std;
using llong = long long;
using P = pair<llong, llong>;

#define BE(x) x.begin(), x.end()

const llong inf = llong(1e18)+7;
const llong mod = 1e9+7;

int main(){
	string s;
	cin >> s;
	if(s[0] == 'Y' && s[1] == 'A' && s[2] == 'K' && s[3] == 'I')
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}