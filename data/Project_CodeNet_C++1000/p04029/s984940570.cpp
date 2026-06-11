#include <bits/stdc++.h>
 
using namespace std;

#ifdef ARTEM
	#define deb(x) x
#else
	#define deb(x)
	const int inf = 1000500;
#endif

void solve();

int main() {
	solve();
}

/* ================ actual code starts here ================ */

void solve() {
	int n;
	cin >> n;
	cout << n * (n + 1) / 2 << endl;
}