#include<bits/stdc++.h>
using namespace std;
#define reg register
#define ll long long
#define mo 1000000007
#define maxn 200005
inline ll read()
{
	ll x=0,w=0;char ch=getchar();
	while(!isdigit(ch))w|=ch=='-',ch=getchar();
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return w?-x:x;
}
int h,w,a,b,ans;
int jc[maxn],inv[maxn];
inline int C(int x,int y)
{
    if(x<y)return 0;
    return 1ll*jc[x]*inv[y]%mo*inv[x-y]%mo;
}
int main()
{
    h=read(),w=read();a=read(),b=read();
    reg int i;jc[0]=inv[0]=inv[1]=1;
    for(i=1;i<=200000;++i)jc[i]=1ll*jc[i-1]*i%mo;
    for(i=2;i<=200000;++i)inv[i]=1ll*inv[mo%i]*(mo-mo/i)%mo;
    for(i=2;i<=200000;++i)inv[i]=1ll*inv[i]*inv[i-1]%mo;
    ans=C(h+w-2,h-1);
    for(i=h-a+1;i<=h;++i)
        ans=(ans-1ll*C(i+b-2,i-1)*C(h-i+w-b-1,h-i)%mo+mo)%mo;
    cout<<ans<<"\n";
	return 0;
}
