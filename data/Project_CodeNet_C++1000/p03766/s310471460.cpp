#include<bits/stdc++.h>
#define gc getchar()
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define Rep(i,v) rep(i,0,(int)v.size()-1)
#define lint long long
#define mod 1000000007
#define db double
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define debug(x) cerr<<#x<<"="<<x
#define sp <<" "
#define ln <<endl
using namespace std;
typedef pair<int,int> pii;
typedef set<int>::iterator sit;
inline int inn()
{
    int x,ch;while((ch=gc)<'0'||ch>'9');
    x=ch^'0';while((ch=gc)>='0'&&ch<='9')
        x=(x<<1)+(x<<3)+(ch^'0');return x;
}
#define P(x) (x>=mod?x-=mod:0)
const int N=1000010;int f[N],s[N],ss[N];
int main()
{
    int n=inn(),ans=1,m=(n-1ll)*n%mod;
    rep(i,1,n) f[i]=(i>=3?ss[i-3]:0)+1,P(f[i]),s[i]=s[i-1]+f[i],P(s[i]),ss[i]=ss[i-1]+s[i],P(ss[i]);
    ans+=(n-1ll)*f[n]%mod,P(ans);rep(i,1,n-1) ans+=(lint)m*f[i]%mod,P(ans);return !printf("%d\n",ans);
}

