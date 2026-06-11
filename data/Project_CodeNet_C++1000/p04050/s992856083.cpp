#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int Maxn = 100010;
int a[Maxn];
int n, m;
int main() {
	int i, j, k;
	scanf("%d%d", &n, &m);
	if(m == 1){
		if(n == 1) printf("1\n1\n1\n");
		else printf("%d\n%d\n%d %d\n", n, 2, 1, n-1);
		return 0;
	}
	int odd = 0;
	for(i = 1; i <= m; i++) scanf("%d", &a[i]), odd += a[i]&1;
	if(odd > 2){ printf("Impossible\n"); return 0; }
	for(i = 1; i <= m; i++) if(a[i]&1){ swap(a[1], a[i]); break; }
	for(i = 2; i <= m; i++) if(a[i]&1){ swap(a[m], a[i]); break; }
	for(i = 1; i <= m; i++) printf("%d%c", a[i], i==m?'\n':' ');
	if(a[1] > 1) printf("%d\n%d ", m, a[1]-1);
	else printf("%d\n", m-1);
	for(i = 2; i < m; i++) printf("%d ", a[i]);
	printf("%d\n", a[m]+1);
	return 0;
}