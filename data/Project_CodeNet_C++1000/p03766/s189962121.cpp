#include<bits/stdc++.h>
#define LL long long
#define db double

using namespace std;
const int N=1e6+10,mod=1e9+7;
int rd()
{
    int x=0,w=1;char ch=0;
    while(ch<'0'||ch>'9'){if(ch=='-') w=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+(ch^48);ch=getchar();}
    return x*w;
}
void ad(int &x,int y){x+=y,x-=x>=mod?mod:0;}
int n,f[N],sm,ans;

int main()
{
///
	n=rd(),f[0]=sm=1;
	ad(ans,1ll*(n-1)*(n-1)%mod),ad(ans,min(2,n-1));
	for(int i=1;i<n;++i)
	{
		f[i]=sm;
		if(i>=2) ad(f[i],mod-f[i-2]);
		ad(sm,f[i]);
		if(i<n-1) ad(ans,1ll*(n-1)*(n-1)%mod*f[i]%mod),ad(ans,1ll*min(i+2,n-1)*f[i]%mod);
	}
	ad(ans,1ll*n*f[n-1]%mod);
	printf("%d\n",ans);
    return 0;
}


