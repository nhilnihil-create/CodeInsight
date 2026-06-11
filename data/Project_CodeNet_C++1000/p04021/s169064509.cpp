#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second

int n, a[100005], ans;
pair<int, int> pr[100005];
bool b[100005];

int main() {
	scanf("%d", &n);
	for ( int i = 1; i <= n; i++ ) {
		scanf("%d", &a[i]);
		pr[i].x = a[i];
		pr[i].y = i;
	}
	sort(pr + 1, pr + n + 1);
	for ( int i = 1; i <= n; i += 2 ) {
		b[pr[i].y] = true;
	}
	for ( int i = 1; i <= n; i += 2 ) {
		if ( !b[i] ) ans++;
	}
	printf("%d\n", ans);
	return 0;
}