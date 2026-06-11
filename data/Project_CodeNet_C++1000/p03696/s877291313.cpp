#include <bits/stdc++.h>
#define REP(i, a, n) for(int i = a; i < n; i++)
using namespace std;

string s;
int n, d;
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> s;
	REP(i, 0, n) {
		if (s[i] == '(') d++;
		else d--;
		if (d < 0) {
			cout << '(';
			d++;
		}
	}
	cout << s;
	while (d--) cout << ')';
}