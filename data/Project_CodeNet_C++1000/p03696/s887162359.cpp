#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int main()
{
	int n;
	string s;
	cin >> n >> s;
	int l = 0, r = 0;
	rep(i, n) {
		if(s[i] == '(') {
			if(r == 0) {
				l++;
			} else {
				l++;
			}
		} else {
			if(l == 0) {
				r++;
			} else {
				l--;
			}
		}
	}
	rep(i, r) cout << '(';
	cout << s;
	rep(i, l) cout << ')';
	cout << endl;
	return 0;
}