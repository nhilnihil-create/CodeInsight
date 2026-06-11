#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,n) for(int i=(a); i<(n); i++)
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s; cin >> s;
	rep(i, s.size()-1) {
		if (s[i]==s[i+1]) {
			cout << i+1 << " " << i+2 << endl;
			return 0;
		} else if (i<s.size()-2 && s[i]==s[i+2]) {
			cout << i+1 << " " << i+3 << endl;
			return 0;
		}
	}
	cout << -1 << " " << -1 << endl;
}