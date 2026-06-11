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
const int N=1e5+5;
vector<int> g[N];
int co[N];
int dvu;
void dfs(int v,int c=1){
    co[v]=c;
    for(int to:g[v]){
        if(!co[to])dfs(to,3-c);
        dvu&=co[to]+co[v]==3;
    }
}
int32_t main(){
    int n,m;
    cin>>n>>m;
    forn(i,m){
        int a,b;
        cin>>a>>b;
        g[a].pb(b);
        g[b].pb(a);
    }
    int iso=0,cd=0,cn=0;
    for(int i=1;i<=n;++i){
        if(!co[i]){
            if(sz(g[i])){
                dvu=1;
                dfs(i);
                if(dvu)cd++;
                else cn++;
            }else iso++;
        }
    }
    int ans=iso*iso+2*iso*(n-iso)+cn*cn+2*cn*cd+cd*cd*2;
    cout<<ans<<'\n';
    return 0;
}