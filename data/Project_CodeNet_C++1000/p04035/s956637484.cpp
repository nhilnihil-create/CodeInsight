#include <bits/stdc++.h>
#define LL long long
#define F(i, a, b) for(int i = a; i <= b; ++i)

using namespace std;

const int maxn = 1e5 + 5;
int n, L, a[maxn];
int p = 0;

int main()
{
	scanf("%d%d", &n, &L);
	F(i, 1, n) scanf("%d", &a[i]);
	F(i, 1, n - 1) if(a[i] + a[i + 1] >= L)
	{
		p = i;
		break;
	}
	if(!p) printf("Impossible");
	else{
		printf("Possible\n");
		F(i, 1, p - 1) printf("%d\n", i);
		for(int i = n - 1; i > p; --i) printf("%d\n", i);
		printf("%d\n", p);
	}
	return 0;
}