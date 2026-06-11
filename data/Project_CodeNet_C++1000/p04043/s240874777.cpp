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
	vector<int> a(3);
	for(int i = 0; i < 3; i++)
		scanf("%d", &a[ i ]);
	sort(a.begin(), a.end());

	if(a[ 0 ] == 5 && a[ 1 ] == 5 && a[ 2 ] == 7)
		printf("YES\n");
	else
		printf("NO\n");
}