#include <cstdio>
#include <algorithm>

#define Rep(i, n) for (int i = 1; i <= n; i ++)
#define Rep0(i, n) for (int i = 0; i <= n; i ++)

using namespace std;

int a[100010];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	int t1 = 0, t2 = 0;
	Rep(i, m){
		scanf("%d", &a[i]);
		if (a[i] & 1){
			if (!t1) t1 = i;
			else if (!t2) t2 = i;
			else {printf("Impossible\n"); return 0;}
		}
	}
	if (t1) swap(a[1], a[t1]); 
	if (t2) swap(a[m], a[t2]);
	Rep(i, m) printf("%d ", a[i]);
	printf("\n");
	if (m == 1) {
		if (a[1] == 1) printf("1\n1\n");
		else {
			printf("2\n");
			printf("1 %d\n", a[1] - 1);
		}
		return 0;
	}
	a[1] --, a[m] ++;
	if (a[1]) printf("%d\n", m);
	else printf("%d\n", m - 1);
	Rep(i, m) if (a[i]) printf("%d ", a[i]);
	
	
	return 0;
}