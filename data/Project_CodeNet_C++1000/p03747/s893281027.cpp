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
int a[N],dir[N],x[N],ans[N];
int32_t main(){
    int n,len,t;
    cin>>n>>len>>t;
    forn(i,n){
        cin>>a[i]>>dir[i];
        if(dir[i]==1)x[i]=(a[i]+t)%len;
        else x[i]=((a[i]-t)%len+len)%len;
    }
    int x0=x[0];
    sort(x,x+n);
    int f=0,s=0;
    forn(i,n){
        if(dir[s]==1&&dir[i]==2){
            int alt=t*2;
            if(a[s]<a[i])alt-=a[i]-a[s];
            else alt-=len-a[s]+a[i];
            if(alt<0)continue;
            int cnt=1+alt/len;
            f+=cnt%n;
        }
        if(dir[s]==2&&dir[i]==1){
            int alt=t*2;
            if(a[s]<a[i])alt-=a[s]-a[i]+len;
            else alt-=a[s]-a[i];
            if(alt<0)continue;
            int cnt=1+alt/len;
            dbg(s,i,cnt);
            f-=cnt%n;
        }
    }
    f=(f%n+n)%n;
    int g=lower_bound(x,x+n,x0)-x;
    if(g<n-1&&x[g+1]==x[g]&&dir[0]==1)g++;
    for(int i=0;i<n;++i,(++f)%=n,(++g)%=n)
        ans[f]=x[g];
    forn(i,n)cout<<ans[i]<<'\n';
    return 0;
}
