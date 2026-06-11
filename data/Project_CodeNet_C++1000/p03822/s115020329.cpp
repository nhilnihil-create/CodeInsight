#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
const int INF=1145141919,MOD=1e9+7;
const long long LINF=8931145141919364364,LMOD=998244353;
inline long long mod(long long n,long long m){return(n%m+m)%m;}
// const int dx[]={1,0,-1,0,1,1,-1,-1},dy[]={0,-1,0,1,1,-1,-1,1};

vector<int> edge[100010];
// dp[i]:=iを根とする木の最大深度
int dfs(int from){
    // cout<<from<<endl;
    vector<int> v;
    for(auto to:edge[from]){
        v.push_back(dfs(to));
    }
    sort(all(v)); reverse(all(v));
    int ret=0,n=v.size();
    rep(i,n){
        ret=max(ret,v[i]+i+1);
    }
    return ret;
}
int main(){
    int n; cin>>n;
    for(int i=2;i<=n;i++){
        int a; cin>>a;
        edge[a].push_back(i);
    }
    cout<<dfs(1)<<endl;
    return 0;
}
