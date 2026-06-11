#include <bits/stdc++.h>
 
using namespace std;

#ifdef ARTEM
	#define deb(x) x
#else
	#define deb(x)
	const int LIMIT = 2 * int(1e5) + 123;
#endif

void solve();

int main() {
	solve();
}

/* ================ actual code starts here ================ */

void solve() {
	int n, l;
	cin >> n >> l;
	vector<string> s(n);
	for(int i = 0; i < n; i++)
		cin >> s[ i ];
	sort(s.begin(), s.end());

	for(string i : s)
		cout << i;
}