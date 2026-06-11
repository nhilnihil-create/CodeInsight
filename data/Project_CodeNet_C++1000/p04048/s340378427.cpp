#include<bits/stdc++.h>
#define rep(i,a,b) for(register int i=a;i<=b;++i)
#define rpd(i,a,b) for(register int i=a;i>=b;--i)
#define rep1(i,x) for(register int i=head[x];i;i=nxt[i])
typedef long long ll;
//const int N=+5;
using namespace std;
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
    while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
ll n,x,ans;
void gcd(ll a,ll b){
	if(b>a)swap(a,b);
	ll shang=a/b,yu=a%b;
	if(yu==0){ans+=b*(shang*2LL-1LL);return;}
	ans+=b*shang*2LL;gcd(b,yu);
}
int main(){
	cin>>n>>x;ans=n;
	gcd(n-x,x);
	printf("%lld\n",ans);
	return 0;
}