#include<bits/stdc++.h>
using namespace std;

using ll=long long;
using Graph=vector<vector<int>>;
int main(){
    int n;
    cin>>n;
    Graph g(n);
    vector<ll> A(n);
    for(int i=0;i<n;i++) cin>>A[i];
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        a--,b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    if(n==2){
        cout<<(A[0]==A[1] ? "YES" : "NO")<<endl;
        return 0;
    }
    vector<ll> dp(n);
    function<ll(int,int)> dfs=[&](int v,int pre){
        int cntC=0;
        ll ma=0;
        ll sum=0;
        for(int i=0;i<g[v].size();i++){
            if(g[v][i]!=pre){
                auto ret=dfs(g[v][i],v);
                sum+=ret;
                ma=max(ma,ret);
                cntC++;
            }
        }
        if(cntC==0) return dp[v]=A[v];
        ll p=sum-A[v];
        if(sum-ma<ma){
            if(p>sum-ma){
                return dp[v]=-1;
            }
        }
        if(p<0) return dp[v]=-1;
        return dp[v]=2*A[v]-sum;
    };
    int root=0;
    for(int i=0;i<n;i++){
        if(g[i].size()>=2){
            root=i;
            break;
        }
    }
    ll val=dfs(root,-1);
    auto isNeg=[](ll x){return x<0;};
    if(val==0 && none_of(dp.begin(),dp.end(),isNeg)){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}