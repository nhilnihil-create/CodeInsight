#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<unordered_map>
#define mod 1000000007
using namespace std;
typedef long long ll;
#define chmax(a,b) a=max(a,b)
#define chmin(a,b) a=min(a,b)
#define mad(a,b) a=(a+b)%mod
#define mul(a,b) a=a*b%mod

#define N 100010
ll n,m,q;
vector<ll> g[N];
ll col[N];
ll dp[N][12];
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
	ll a,b; cin>>a>>b;
	g[a].push_back(b);
	g[b].push_back(a);
    }
    for(int i=1;i<=n;i++)g[i].push_back(i);
    for(int i=1;i<=n;i++)for(int d=0;d<12;d++)dp[i][d]=0;
    col[0]=0;
    cin>>q;
    for(ll i=1;i<=q;i++){
	ll a,b; cin>>a>>b>>col[i];
	chmax(dp[a][b],i);
    }
    for(int d=11;d>0;d--){
	for(int i=1;i<=n;i++)for(auto j:g[i]){
	    chmax(dp[j][d-1],dp[i][d]);
	}
    }
    for(int i=1;i<=n;i++){
	cout<<col[dp[i][0]]<<endl;
    }
}


