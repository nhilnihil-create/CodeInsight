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
int a[N];
void no(){
    cout<<"NO\n";
    exit(0);    
}
void dfs(int v,int p=0){
    int sum=0,big=0,lf=1;
    for(int to:g[v]){
        if(to^p){
            dfs(to,v);
            lf=0;
            sum+=a[to];
            upx(big,a[to]);
        }
    }
    if(!lf){
        int f=max(0ll,big-sum/2);
        if(f>a[v])no();
        int x=(a[v]-f)*2-(sum-f);
        a[v]=x+f;
        if(x<0||a[v]<0||a[v]>sum)no();
    }
}
int32_t main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    forn(i,n-1){
        int x,y;
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }
    int s=-1;
    for(int i=1;i<=n;++i)if(sz(g[i])>1)s=i;
    if(s==-1){
        if(a[1]==a[2])cout<<"YES\n";
        else cout<<"NO\n";
    }else{
        dbg(s);
        dfs(s);
        if(a[s])cout<<"NO\n";
        else cout<<"YES\n";
    }
    return 0;
}