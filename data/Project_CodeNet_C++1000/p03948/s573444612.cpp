#include <cstdio>
int n, a, m, d, mx, mc;
int main() {
	scanf("%d%*d%d", &n, &m);
	for(int i=1; i<n; i++) {
		scanf("%d", &a);
		d = a-m;
		if(d > mx) mx = d, mc = 1;
		else if(d == mx) mc++;
		if(a < m) m = a;
	}
	printf("%d", mc);
	return 0;
}