//joisino's travel

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define nvarep(n,a) ll n;cin>>n;vector<ll>a(n);rep(i,0,n)cin>>a[i]
#define vecrep(n,a,type) vector<type>a(n);rep(i,0,n)cin>>a[i]
#define lcm(a,b) (a/__gcd(a, b)*b)
#define range(a) (a).begin(),(a).end() 
#define pb push_back
#define mp make_pair
#define nnn "\n"
#define spa " "
using p = pair<ll,ll>;
using graph = vector<vector<ll>>;
const int inf = 2147483647;//2*10^9
const ll INF = 9223372036854775807;//9*10^18
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

signed main (){
    int n,m,R;cin>>n>>m>>R;
    vecrep(R,r,int);
    vector<vector<int>>c(n,vector<int>(n,inf));
    rep(i,0,n)c[i][i]=0;
    rep(i,0,m){
        int a,b,d;cin>>a>>b>>d;
        c[a-1][b-1]=d;
        c[b-1][a-1]=d;
    }
    rep(k,0,n)rep(i,0,n)rep(j,0,n)chmin(c[i][j],c[i][k]+c[k][j]);
    sort(range(r));
    int ans=inf;
    for(int i=0;next_permutation(range(r));i++){
        if(i==0)prev_permutation(range(r));
        int t=0;
        rep(i,1,R)t+=c[r[i-1]-1][r[i]-1];
        ans=min(ans,t);
    }
    cout<<ans<<nnn;
    return 0;
}