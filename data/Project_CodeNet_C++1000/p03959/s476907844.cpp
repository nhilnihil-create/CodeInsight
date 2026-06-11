#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int> >;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define irep(i, n) for(int i = n-1; i >= (int)0; i--)
#define reprep(i,j,h,w) rep(i,h)rep(j,w)
#define rrep(i,m,n) for(int i = m; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define aall(x,n) (x).begin(),(x).begin()+(n)
#define VEC(type,name,n) std::vector<type> name(n);rep(i,n)std::cin >> name[i];
#define pb push_back
#define pf push_front
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define mp make_pair
#define sum accumulate
#define keta fixed<<setprecision
#define vvector(name,typ,m,n,a)vector<vector<typ> > name(m,vector<typ> (n,a))
#define vvvector(name,t,l,m,n,a) vector<vector<vector<t> > > name(l, vector<vector<t> >(m, vector<t>(n,a)));
#define vvvvector(name,t,k,l,m,n,a) vector<vector<vector<vector<t> > > > name(k,vector<vector<vector<t> > >(l, vector<vector<t> >(m, vector<t>(n,a)) ));
typedef long long ll;
const int INF = 2000000000;
const ll INF64 = 1000000000000000ll;
const ll MOD = 1000000007LL;
int main(){
    int n;
    std::cin >> n;
    std::vector<ll> a(n);
    std::vector<ll> b(n);
    
    rep(i,n)std::cin >> a[i];
    rep(i,n)std::cin >> b[i];
    std::vector<bool> cona(n,0),conb(n,0),con(n,0);
    std::vector<ll> h(n);
    
    cona[0]=1;
    rep(i,n-1){
        if(a[i+1]!=a[i])cona[i+1]=1;
    }
    conb[n-1]=1;
    irep(i,n-1){
        if(b[i+1]!=b[i])conb[i]=1;
    }
    bool han=0;
    rep(i,n){
        
        if(cona[i]&&conb[i]&&a[i]!=b[i])han=1;
        if(cona[i]&&a[i]>b[i])han=1;
        if(conb[i]&&a[i]<b[i])han=1;
    }
    if(han){
        std::cout << 0 << std::endl;
        exit(0);
    }
    rep(i,n)if(conb[i]||cona[i])con[i]=1;
    ll ans=1ll;
    rep(i,n){
        if(!con[i]){
         //   std::cout << i << std::endl;
            ans*=min(a[i],b[i]);
            ans%=MOD;
        }
    }
    std::cout << ans << std::endl;
}