#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	string s;
	cin >> s;

	int l, r;
	rep(i,s.size()) {
		if (s[i] == 'A') {
			l = i;
			break;
		}
	}
	for (int i = s.size()-1; i >= 0; i--) {
		if (s[i] == 'Z') {
			r = i;
			break;
		}	
	}

	cout << r-l+1 << endl;

	return 0;
}
