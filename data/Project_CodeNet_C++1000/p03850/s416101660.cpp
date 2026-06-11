#include<iostream>
#include<cstring>
#include<cstdio>
#define MN 100000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
char s[5];long long f[MN+5][4];
int a[MN+5],op[MN+5],n;
#define S(x) ((x)?-1:1)
inline void R(long long&x,long long y){y>x?x=y:0;}
int main()
{
	n=read();a[1]=read();
	for(int i=2;i<=n;++i) scanf("%s",s),op[i]=s[0]=='-',a[i]=read();
	memset(f,200,sizeof(f));f[1][0]=a[1];
	for(int i=2;i<=n;++i)
		for(int j=0;j<4;++j) 
			for(int k=0;k<2;++k)
			{
				int OP=j>>k&1;
				if(!k) R(f[i][j],f[i-1][j]+S(OP^op[i])*a[i]),
					   R(f[i][(j&2)|(OP^op[i])],f[i-1][j]+S(OP^op[i])*a[i]);
				R(f[i][OP<<1|(OP^op[i])],f[i-1][j]+S(OP^op[i])*a[i]);	
			}
	long long ans=-1e18;
	for(int i=0;i<4;++i) R(ans,f[n][i]);
	printf("%lld\n",ans);
	return 0;
}

