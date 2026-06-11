#include <bits/stdc++.h>
#define res register int
#define ll long long
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define INF 1000000007
#define gc getchar()
#define MAXN 10000005
#define lc pos<<1
#define rc pos<<1|1
using namespace std;

inline int read()
{
    int ch=gc,f=0;
    int x=0;
    while(ch<'0'||ch>'9')
    {
        f|=ch=='-';
        ch=gc;
    }
    while(ch>='0'&&ch<='9')
    {
        x=x*10+ch-'0';
        ch=gc;
    }
    return f?-x:x;
}
const int kcz=INF;
int n,m;
int k;
int f[2005][2005];
int js[4000005],inv[4000005];
inline int power(int a,int p)
{
	int ret=1;
	while(p)
	{
		if(p&1)
		ret=1ll*ret*a%kcz;
		a=1ll*a*a%kcz;
		p>>=1;
	}
	return ret;
}
inline void init(int n)
{
	js[0]=inv[0]=1;
	for(int i=1;i<=n;i++)
	js[i]=i*1ll*js[i-1]%kcz;
	inv[n]=power(js[n],kcz-2);
	for(int i=n-1;i;i--)
	inv[i]=(i+1)*1ll*inv[i+1]%kcz;
}
inline int C(int n,int m)
{
	return js[n]*1ll*inv[m]%kcz*inv[n-m]%kcz;
}
int main()
{
	n=read(),m=read();
	f[n][n]=1;
	init(4000000);
	if(m==1)
	{
		puts("1");
		return 0;
	}
	for(int i=n-1;~i;i--)
	{
		for(int j=n;j>=i;j--)
		{
			f[i][j]=(f[i+1][j]+f[i][j+1]*1ll*(j+1)%kcz*C(i+(j+1)*(m-1)-1,m-2)%kcz)%kcz;
		}
	}
	printf("%d\n",f[0][0]);
	return 0;
}