#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 50;

int n, pos, a[N];

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", a + i);
	sort(a + 1, a + 1 + n, greater<int> () );
	for(pos = 1; pos <= n; ++pos) {
		if(a[pos] < pos) break;
	}
	--pos;
	cerr << "pos = " << pos << '\n';
	if((a[pos] - pos) & 1) return 0 * puts("First");
	for(int j = n; j > pos; --j) {
		if(a[j] == pos) {
			if((j - pos) & 1)
				return 0 * puts("First");
			break;
		}
	}
	puts("Second");
	return 0;
}
