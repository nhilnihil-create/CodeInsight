#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
#include<set>
#include<stack>
#include<queue>
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define rep(i,n) for(ll i=0;i<n;i++)
#define repr(i,n) for(ll i=n;i>=0;i--)
#define INF 1e9+7
#define LLINF 1e18
using namespace std;
const int MOD = 1e9 +7;

int n,k;
vector<int> E[2010];

int dfs(int x,int p,int d,int mx){
    int ans=1;
    if(d !=mx){
        for(int y:E[x]){
            if(y==p) continue;
            ans +=dfs(y,x,d+1,mx);
        }
    }
    return ans;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n>>k;
    rep(i,n-1){
        int a,b;
        cin >>a>>b;
        E[a].pb(b);
        E[b].pb(a);
    }
    int ans=0;
    if(k%2==0){
        for(int v=1;v<=n;v++){
            ans=max(ans,dfs(v,-1,0,k/2));
        }
    }
    else{
        for(int v=1;v<=n;v++){
            for(int u : E[v]){
                ans=max(ans,dfs(v,u,0,k/2)+dfs(u,v,0,k/2));
            }
        }
    }
    cout<<n-ans<<endl;
    return 0;
}