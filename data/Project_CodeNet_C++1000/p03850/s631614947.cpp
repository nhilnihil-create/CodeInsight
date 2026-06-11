#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=int(1e5+5);
typedef long long LL;
#define INF LL(1e15)
LL s1,s2,as,n;
LL sz[MAXN],fh[MAXN];
char c[5];
int main()
{
	scanf("%lld",&n);
	scanf("%lld",&as);
	getchar();
	for(LL i=1;i<=n-1;i++) {
		scanf("%s",c);
		scanf("%d",&sz[i]);
		fh[i]=c[0];
	}
	s1=s2=-INF;
	for(LL i=1;i<=n-1;i++) {
		if(fh[i]=='-') {
			as-=sz[i];
			s2-=sz[i];
			s1+=sz[i];
			s2=max(s1,s2);
			s1=max(as,s1);
			as=max(s1,s2);
		}
		else {
			as+=sz[i];
			s2+=sz[i];
			s1-=sz[i];
			s1=max(s1,s2);
			as=max(s1,as);
		}
	}
	printf("%lld",as); 
}
/*
5
7 - 8 + 9 - 10 - 2*/