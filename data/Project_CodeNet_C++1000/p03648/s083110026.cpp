#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define		CH		ch=(getchar())

inline		int		IN(){
	int x=0,f=1;char ch;
	for (CH;ch>'9'||ch<'0';CH) if (ch=='-') f=-1;
	for (;ch>='0'&&ch<='9';CH) (x*=10)+=ch-'0';
	return x*f;
}

int i,j,k,l,n,m;
long long K,f[105],x,y;

int main(){
	scanf("%lld",&K);
	puts("50");
	x=K/50;
	for (i=1;i<=50;i++) f[i]=x+49;
	y=K%50;
	for (i=1;i<=y;i++) f[i]++;
	for (i=y+1;i<=50;i++) f[i]-=y;
	for (i=1;i<=50;i++) printf("%lld ",f[i]); 
}
