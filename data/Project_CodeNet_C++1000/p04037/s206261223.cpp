#include <algorithm>
#include <iostream>
#include <cstdio>

using namespace std;

const int Maxn = 100010;
int n;
int a[Maxn];

inline bool comp(const int &x , const int &y) {
	return x > y;
}

int main() {
	
	scanf("%d",&n);
	for(register int i=1; i<=n; i++)
		scanf("%d",&a[i]);
	
	sort(a+1,a+n+1,comp);
	
	register int x = 1;
	for(; x<=n; x++)
		if(a[x] < x)
			break;
	x --;
	
	register int u = a[x] - x;
	register int v = x;
	for(; v<=n; v++)
		if(x > a[v])
			break;
	v -= x + 1;
	
	if(u % 2 == 1 || v % 2 == 1)	puts("First");
	else	puts("Second");
	
	return 0;
	
}