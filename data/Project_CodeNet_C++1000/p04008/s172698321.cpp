#include <bits/stdc++.h>
typedef long long ll;
const int INF = 1e9,MOD = 1e9+7,ohara = 1e6;
const ll LINF = 1e18;
using namespace std;

#define rep(i,n) for(ll (i)=0;(i)<(int)(n);(i)++)
#define rrep(i,a,b) for(ll i=(a);i<(b);i++)
#define rrrep(i,a,b) for(ll i=(a);i>=(b);i--)
#define all(v) (v).begin(), (v).end()
#define pb(q) push_back(q)
#define Size(n) (n).size()
#define Cout(x) cout<<(x)<<endl

ll n,cnt=0,ans=0,a,b[ohara],c,d,cmp,cmpp,m,h,w,x,y,sum=0,pos,k;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
//int dy[]={-1,0,1,-1,1,-1,0,1};
//int dx[]={-1,-1,-1,0,0,1,1,1};
string alph("abcdefghijklmnopqrstuvwxyz"),s;
bool fl,visited[ohara];
struct edge{int to,cost;};
vector<ll> g[ohara];

//-------------------------↓↓↓↓↓↓------------------------

ll dfs(ll parent,ll now){
    ll now_depth=0;
    rep(i,Size(g[now])){
        ll to=g[now][i];
        now_depth=max(dfs(now,to),now_depth);
    }
    if(now_depth==k-1){
        if(parent!=0)ans++;
        return 0;
    }
    else return now_depth+1;
}

int main(void){
       cin.tie(0);
    ios::sync_with_stdio(false);
      
    cin>>n>>k;
    rep(i,n){
        cin>>a;
        if(i==0&&a!=1)ans=1;
        if(i==a-1)continue;
        if(i==0)continue;
        b[i]=a-1;
        a--;
        g[a].push_back(i);
    }
    dfs(0,0);
    Cout(ans);
    return 0;
}
