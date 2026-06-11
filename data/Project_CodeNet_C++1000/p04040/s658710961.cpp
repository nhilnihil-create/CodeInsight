//#pragma GCC optimize(2)


#include<bits/stdc++.h>
using namespace std;
/*#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#include<ext/pb_ds/trie_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#include<ext/rope>*/
//using namespace __gnu_cxx;
//using namespace __gnu_pbds;
//void err(istream_iterator<string> it){cerr<<endl;}
//template<typename T, typename... Args>void err(istream_iterator<string> it, T a, Args... args){cerr << *it << " = " << a << " , ";err(++it, args...);}
//#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define mem(a,b) memset((a),b,sizeof((a)))
#define fpre(x) cout<<fixed<<setprecision(x)
#define clr(v) (v).clear()
#define pii pair<int,int>
#define pdd pair<double,double>
#define pli pair<ll,int>
#define pll pair<ll,ll>
#define mp make_pair
#define eb emplace_back
#define pb emplace_back
#define ll long long
#define ld long double
#define ull unsigned long long
#define uint unsigned int
#define ushort unsigned short
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define lowbit(i) (i&(-i))
#define lson rt<<1
#define rson lson|1
#define fi first
#define se second
const double eps=1e-7;
const double pi=acos(-1);
inline int dcmp(double x)
{
    if(x<-eps)
        return -1;
    if(x>eps)
        return 1;
    return 0;
}
//-----------------------------------------------head

const int maxn=2e5+5;
const ll mod=1e9+7;
ll f[maxn+5],invf[maxn+5];
ll qp(ll x,ll n)
{
    x%=mod;
    ll r=1;
    while(n)
    {
        if(n&1)
            r=r*x%mod;
        x=x*x%mod;
        n>>=1;
    }
    return r;
}
void init()
{
    f[0]=1;
    for(int i=1;i<=maxn;++i)
        f[i]=f[i-1]*i%mod;
    invf[maxn]=qp(f[maxn],mod-2);
    for(int i=maxn-1;~i;--i)
        invf[i]=invf[i+1]*(i+1)%mod;
}
ll c(int n,int m)
{
    return f[n]*(invf[m]*invf[n-m]%mod)%mod;
}
int main()
{
    init();
    int h,w,a,b;
    while(~scanf("%d%d%d%d",&h,&w,&a,&b))
    {
        ll r=0;
        for(ll i=b+1;i<=w;++i)
        {
            ll tmp=c(h-a+i-2,h-a-1)*c(w-i+a-1,w-i)%mod;
            r=(r+tmp)%mod;
        }
        printf("%lld\n",r);
    }
}

/*
























*/







