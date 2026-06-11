#include <iostream>
#include <cstdio>
#include <cstring>
#define FUP(i,x,y) for(register int i=(x);i<=(y);i++)
#define FDW(i,x,y) for(register int i=(x);i>=(y);i--)
#define MAXN 40
#define INF 0x3f3f3f3f
using namespace std;
inline int read(){
    int w=0,flg=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')flg=-1;ch=getchar();}
    while(ch<='9'&&ch>='0'){w=w*10-'0'+ch,ch=getchar();}
    return w*flg;
}
int n,m1,m2,a,b,c,ans=INF,cnt=1,suma,sumb,aa,bb;
int f[410][410];
int main(){
	memset(f,0x3f,sizeof(f));
	f[0][0]=0;
	n=read(),m1=aa=read(),m2=bb=read();
	FUP(i,1,n)
	{
		a=read(),b=read(),c=read();
		suma+=a,sumb+=b;
		FDW(j,suma,a)
		{
			FDW(k,sumb,b)
			{
				f[j][k]=min(f[j][k],f[j-a][k-b]+c);
			}
		}
	}
	while(m1<=suma&&m2<=sumb)
	{
		ans=min(ans,f[m1][m2]);
		//printf("%d,%d:%d\n",m1,m2,f[m1][m2]);
		m1+=aa,m2+=bb;
	}
	printf("%d\n",ans==INF?-1:ans);
    return 0;
}