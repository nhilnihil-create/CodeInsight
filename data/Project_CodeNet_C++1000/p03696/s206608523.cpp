#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 25;
const int MOD = 1e9+7;
 
int main() {
	int n;
	string s;
	cin >> n >> s;
	int l = 0, r = 0;
	int gap = 0;
	rep(i,n) {
		if (s[i]=='(') l++;
		else r++;
		gap = min(gap,l-r);
	}
	int ds = l-r;
	rep(i,-gap) cout << '(';
	cout << s;
	rep(i,ds-gap) cout << ')';
	cout << endl; 
	return 0;
}