#include<bits/stdc++.h>
#define LL long long

using namespace std;
const int N=1e5+10;
int rd()
{
    int x=0,w=1;char ch=0;
    while(ch<'0'||ch>'9'){if(ch=='-') w=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+(ch^48);ch=getchar();}
    return x*w;
}
LL n,a[N],z[N],f[N][3];
char cc[2];

int main()
{
    //////
	n=rd(),z[1]=1,a[1]=rd();
	for(int i=2;i<=n;++i) scanf("%s",cc),z[i]=cc[0]=='-'?-1:1,a[i]=rd();
	memset(f,-0x3f3f3f,sizeof(f));
	f[1][0]=a[1];
	for(int i=2;i<=n;++i)
	{
		f[i][0]=max(f[i][0],f[i-1][0]+z[i]*a[i]);
		f[i][0]=max(f[i][0],f[i-1][1]-z[i]*a[i]);
		f[i][1]=max(f[i][1],f[i-1][1]-z[i]*a[i]);
		f[i][0]=max(f[i][0],f[i-1][2]+z[i]*a[i]);
		f[i][1]=max(f[i][1],f[i-1][2]+z[i]*a[i]);
		f[i][2]=max(f[i][2],f[i-1][2]+z[i]*a[i]);
		if(z[i]<0)
		{
			f[i][1]=max(f[i][1],f[i-1][0]+z[i]*a[i]);
			f[i][2]=max(f[i][2],f[i-1][1]-z[i]*a[i]);
		}
	}
	printf("%lld\n",f[n][0]);
    return 0;
}

