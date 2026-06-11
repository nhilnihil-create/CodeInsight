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

ll n,cnt,ans,a[ohara],b,c,d,tmp,tmpp,m,h,w,x,y,sum,pos,k,dp[ohara];
ld doua;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
//int dy[]={-1,0,1,-1,1,-1,0,1};
//int dx[]={-1,-1,-1,0,0,1,1,1};
string alph("abcdefghijklmnopqrstuvwxyz"),s;
bool fl;
struct edge{int to,cost;};
vector<ll> g[ohara];
ll out[ohara];

//-------------------------↓↓↓↓↓↓------------------------

void dfs(ll now){
    rep(i,Size(g[now])){
        dfs(g[now][i]);
    }
    vector<ll> chi;
    rep(i,Size(g[now])){
        chi.push_back(dp[g[now][i]]);
    }
    sort(all(chi));
    reverse(all(chi));
    ll ma=0;
    rep(i,Size(chi)){
        ma=max(ma,chi[i]+i+1);
    }
    dp[now]=ma;
    return;
}

int main(void){
       cin.tie(0);
    ios::sync_with_stdio(false);

    cin>>n;
    rrep(i,2,n+1)cin>>a[i];
    rrep(i,2,n+1){
        g[a[i]].push_back(i);

    }
    dfs(1LL);
    Cout(dp[1]);
    return 0;
}
