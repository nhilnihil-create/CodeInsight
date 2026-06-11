// Phoenix

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn=2010,inf=1e9+10;

vector<int>v[maxn];
int dp[maxn][maxn],n,k,ans=inf;

void dfs(int u,int par=-1){
    for(int y:v[u]){
	if(y!=par){
	    dfs(y,u);
	    dp[u][0]+=dp[y][0]+1;
	    for(int i=1;2*i<=k;i++)
		dp[u][i]+=dp[y][i-1];
	}
    }
    for(int i=(k+2)/2;i<=k;i++){
	dp[u][i]=inf;
    }
    for(int y:v[u]){
	if(y!=par){
	    for(int i=(k+2)/2;i<k;i++)
		dp[u][i]=min(dp[u][i],dp[u][k-i]-dp[y][k-i-1]+dp[y][i-1]);
	    dp[u][k]=min(dp[u][k],dp[u][0]-dp[y][0]-1+dp[y][k-1]);
	}
    }
    for(int i=1;i<=k;i++){
	dp[u][i]=min(dp[u][i],dp[u][i-1]);
    }
    ans=min(ans,dp[u][k]+n-dp[u][0]-1);
}

int main(){
    cin>>n>>k;
    for(int i=1;i<n;i++){
	int a,b;cin>>a>>b;
	v[a].PB(b);
	v[b].PB(a);
    }
    dfs(1);
    cout<<ans<<endl;
    return 0;
}



