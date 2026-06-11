#include <bits/stdc++.h>

using namespace std;
const int maxn = 500010, inf = 1e9 + 233;
int n;
int p[maxn], a[maxn], b[maxn], deltaa[maxn], deltab[maxn];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &p[i]);
		
	//puts("qwq");
		
	for (int i = 1; i <= n; i++)
		a[i] = i, b[i] = n - i + 1;
		
//			puts("qwq");
		
	for (int i = 1; i <= n; i++)
		deltaa[p[i] + 1] += 20000 - i, deltab[p[i] - 1] += 20000 - i;
		
			//puts("qwq");
		
	for (int i = 1; i <= n; i++)
		deltaa[i] += deltaa[i - 1], a[i] += deltaa[i];
		
		//	puts("qwq");
		
	
	for (int i = n; i; i--)
		deltab[i] += deltab[i + 1], b[i] += deltab[i];//, printf("i:%d b[i]:%d deltab[i]:%d\n", i, b[i], deltab[i]);
		
		//	puts("qwq");
		
	for (int i = 1; i <= n; i++)
		printf("%d ", a[i]);
	puts("");

	for (int i = 1; i <= n; i++)
		printf("%d ", b[i]);
	puts("");

}