#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#define FUP(i,x,y) for(int i=(x);i<=(y);i++)
#define FDW(i,x,y) for(int i=(x);i>=(y);i--)
#define MAXN 40
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define ll long long
#define db double
using namespace std;
int read(){
    int w=0,flg=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')flg=-1;ch=getchar();}
    while(ch<='9'&&ch>='0'){w=w*10-'0'+ch,ch=getchar();}
    return w*flg;
}
int n,m1,m2,a[MAXN],b[MAXN],c[MAXN],ans=INF,cnt=1,suma,sumb;
int f[410][410];
int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
int main(){
	
	memset(f,0x3f,sizeof(f));
	f[0][0]=0;
	n=read(),m1=read(),m2=read();
	FUP(i,1,n)
	{
		a[i]=read(),b[i]=read(),c[i]=read();
		suma+=a[i],sumb+=b[i];
		FDW(j,suma,a[i])
		{
			FDW(k,sumb,b[i])
			{
				f[j][k]=min(f[j][k],f[j-a[i]][k-b[i]]+c[i]);
				if(j*1.0/m1==k*1.0/m2)
				{
					ans=min(ans,f[j][k]);
					//printf("%d,%d\n",j,k);
				}
			}
		}
		//printf("%d\n",f[2][2]);
	}
	printf("%d\n",ans==INF?-1:ans);
    return 0;
}