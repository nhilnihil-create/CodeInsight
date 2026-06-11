#include <bits/stdc++.h>

#define int long long

using namespace std;
#define rep(i,s,n) for(int i = s;i<n;i++)
#define repe(i,s,n) for(int i = s;i<=n;i++)
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
static const ll maxLL = (ll)1 << 62;
const ll MOD=1000000007,INF=1e18;
int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};

int n,m,x[100010],y[100010];

signed main(){
    cin>>n>>m;
    rep(i,0,n)cin>>x[i];
    rep(i,0,m)cin>>y[i];
    
    int ans1=0,ans2=0;
    rep(i,0,n){
        ans1+=i*x[i]-(n-i-1)*x[i];
        ans1%=MOD;
    }
    rep(i,0,m){
        ans2+=i*y[i]-(m-i-1)*y[i];
        ans2%=MOD;
    }
    cout<<(ans1*ans2)%MOD<<endl;
    
    
    
    
    
    
    
}