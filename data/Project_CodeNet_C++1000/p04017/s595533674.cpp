#include <bits/stdc++.h>
using namespace std;using ll=long long;using uint=unsigned int;using pii=pair<int,int>;using pll=pair<ll,ll>;using ull = unsigned long long;using ld=long double;template<typename T>void _(const char*s,T h){cerr<<s<<" = "<<h<<"\n";}template<typename T,typename...Ts>void _(const char*s,T h,Ts...t){int b=0;while(((b+=*s=='(')-=*s==')')!=0||*s!=',')cerr<<*s++;cerr<<" = "<<h<<",";_(s+1,t...);}// break continue pop_back 998244353
#define int ll
#define pii pll
#define f first
#define s second
#define pb emplace_back
#define forn(i,n) for(int i=0;i<(n);++i)
#define sz(a)((int)(a).size())
#define sqr(x) ((x)*(x))
struct init{init(){cin.tie(0);iostream::sync_with_stdio(0);cout<<fixed<<setprecision(10);cerr<<fixed<<setprecision(5);}~init(){
#ifdef LOCAL
#define dbg(...) _(#__VA_ARGS__,__VA_ARGS__)
cerr<<"Time elapsed: "<<(double)clock()/CLOCKS_PER_SEC<<"s.\n";
#else
#define dbg(...) 
#endif
}}init;template<typename T,typename U>void upx(T&x,U y){if(x<y)x=y;}template<typename T,typename U>void upn(T&x,U y){if(x>y)x=y;}mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());const int D=4,dx[]={+1,0,-1,0},dy[]={0,+1,0,-1};
const int N=1e5+5,L=17;
int x[N];
int go[N][L];
int og[N][L];
int32_t main(){
    int n;cin>>n;
    for(int i=1;i<=n;++i)cin>>x[i];
    int pos=n,l,q;
    cin>>l>>q;
    for(int i=n;i>=1;--i){
        while(x[i]+l<x[pos])pos--;
        go[i][0]=pos;
        for(int j=1;j<L;++j)go[i][j]=go[go[i][j-1]][j-1];
    }
    pos=1;
    for(int i=1;i<=n;++i){
        while(x[i]-l>x[pos])pos++;
        og[i][0]=pos;
        for(int j=1;j<L;++j)og[i][j]=og[og[i][j-1]][j-1];
    }
    while(q--){
        int a,b;
        cin>>a>>b;
        int ans=1;
        if(a<b){
            for(int i=L-1;i>=0;--i){
                if(go[a][i]<b){
                    a=go[a][i];
                    ans+=1<<i;
                }
            }
        }else{
            for(int i=L-1;i>=0;--i){
                if(og[a][i]>b){
                    a=og[a][i];
                    ans+=1<<i;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}