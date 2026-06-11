#include<cstdio>
#include<cctype>
#include<cstring>
#define max(a,b) (a>b?a:b)
#define reg register
typedef long long ll;
template<typename T>inline T read(){
    reg T x=0;reg short f=1;reg char c=getchar();
    for(;!isdigit(c);f=c=='-'?-1:1,c=getchar());
    for(;isdigit(c);x=x*10+(c^48),c=getchar());
    return x*f;
}
ll ans,a,b,c;
int main(){
	ans+=(a=read<ll>());ans+=read<ll>();read<ll>();ans+=(b=read<ll>());ans+=(c=read<ll>());read<ll>();read<ll>();
	if(!(((a&1)+(b&1)+(c&1))%3))printf("%lld\n",ans);
	else if(a&&b&&c||((a&1)+(b&1)+(c&1))%3==1)printf("%lld\n",ans-1);
	else printf("%lld\n",ans-2);
    return 0;
}