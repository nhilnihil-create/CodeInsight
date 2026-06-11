#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
const int INF=1e9,MOD=1e9+7,ohara=1e6+10;
const ll LINF=1e18;
using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define rrep(i,a,b) for(int i=(a);i<(b);i++)
#define rrrep(i,a,b) for(int i=(a);i>=(b);i--)
#define all(v) (v).begin(), (v).end()
#define Size(n) (n).size()
#define Cout(x) cout<<(x)<<endl
#define Cerr(x) cerr<<(x)<<endl
#define fi first
#define se second

ll n,cnt,ans,a[ohara],b,c,d,tmp,tmpp,m,h,w,x,y,sum,pos,k;
ld doua;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
//int dy[]={-1,0,1,-1,1,-1,0,1};
//int dx[]={-1,-1,-1,0,0,1,1,1};
string alph("abcdefghijklmnopqrstuvwxyz"),s;
bool fl;
struct edge{int to,cost;};
vector<ll> g[ohara];
ll vi[ohara];
unordered_map<ll,ll> used;
ll ha[ohara];
ll ha_cou=0;
ll dp[ohara];
vector<ll> gyaku[ohara];

//-------------------------↓↓↓↓↓↓------------------------

ll dfs(ll parent,ll now){
    ll depth=0;
    rep(i,Size(g[now])){
        depth=max(dfs(now,g[now][i]),depth);
    }
    //cerr<<now+1<<" "<<depth<<"\n";
    if(depth==k-1){
        if(parent!=0)ans++;
        return 0;
    }
    else return depth+1;
}

int main(void){
       cin.tie(0);
    ios::sync_with_stdio(false);

    cin>>n>>k;
    rep(i,n)cin>>a[i];
    if(a[0]!=1)ans=1;
    rrep(i,1,n){
         g[a[i]-1].push_back(i);
         gyaku[i].push_back(a[i]-1);
    }
    dfs(0LL,0LL);
    Cout(ans);
    return 0;
}
