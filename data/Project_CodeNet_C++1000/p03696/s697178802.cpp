#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n; string s; cin >> n >> s;
	int a = 0;
	int f = -1;
	// cout << n << ' ' << s << endl;
	for (int i = 0; i < n; i++) {
		if (s[i] == ')') {
			if (f == -1) f = i;	// The index of the first ')' character
			a--;
			if (a < 0) {
				s.insert(f, "(");
				a++; n++; i++;
			}
		}  else {
			a++;
		}

		// cout << a << ' ' << s << endl;
	}
	string s2 = "";
	for (int i = 0; i < a; i++) s2 += ")";
	s.insert(n, s2);
	cout << s;
	
	return 0;
}