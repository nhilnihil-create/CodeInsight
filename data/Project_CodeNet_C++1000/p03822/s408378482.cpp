#include <bits/stdc++.h>
using namespace std;
 
#define int long long
//#define uint __int128_t
 
#define pb push_back
#define fi first
#define se second
#define rep(i,s,n) for(int i = s;i<n;i++)
#define repe(i,s,n) for(int i = s;i<=n;i++)
#define rrep(i,s,n) for(int i = (n)-1;i>=(s);i--)
#define all(v) (v).begin(),(v).end()
#define chmin(a,b) a=min((a),(b))
#define chmax(a,b) a=max((a),(b))
#define low(a,b) lower_bound(all(a),(b))-(a).begin()
#define upp(a,b) upper_bound(all(a),(b))-(a).begin()
#define endl '\n'
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0)
typedef long long ll;
typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<vint> vvint;
typedef vector<pint>vpint;
typedef pair<pint,int> P1;
typedef pair<int,pint> P2;
typedef pair<pint,pint> PP;
static const ll maxLL = (ll)1 << 62;
const ll MOD=1000000007;
const ll INF=1e18;

int N;
vint v[100010];
int dp[100010];
bool used[100010];

int dfs(int d){
    if(used[d])return dp[d];
    used[d]=true;
    vint tmp;
    for(auto e:v[d])tmp.pb(dfs(e));
    sort(all(tmp),greater<int>());
    rep(i,0,(int)tmp.size())dp[d]=max(dp[d],1+i+tmp[i]);
    return dp[d];
}

signed main() {
    IOS();
    //(1ll<<N)シフト演算のオーバーフローに気をつける
    cin>>N;
    rep(i,1,N){
        int a;cin>>a;
        a--;
        v[a].pb(i);
    }
    
    
    cout<<dfs(0)<<endl;
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
    return 0;
}