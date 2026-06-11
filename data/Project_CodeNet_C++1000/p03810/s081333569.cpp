#include <cstdio>
#define MAXN 100010
#define LL long long

int n;
int a[MAXN];

int gcd(int x,int y){
	if(!y) return x;
	return gcd(y,x%y);
}

bool gao(){
	int c0=0,p1;
	for(int i=1;i<=n;i++)
		if(a[i]&1) p1=i;
		else c0++;
	if(c0&1) return 1;
	if(n-c0>1) return 0;
	int g=0;
	for(int i=1;i<=n;i++)
		if(a[i]&1){
			if(a[i]==1) return 0;
			g=gcd(g,a[i]-1);
		}else g=gcd(g,a[i]);
	for(int i=1;i<=n;i++) a[i]/=g;
	return !gao();
}

int main(){
#ifdef DEBUG
	freopen("D.in","r",stdin);
#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	if(gao()) puts("First");
	else puts("Second");
}
