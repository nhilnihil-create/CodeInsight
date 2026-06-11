#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define all(a) (a).begin(),(a).end()
#define pb emplace_back
#define INF (1e9+1)

vector<int> G[100000];
vector<int> a(100000);
vector<int> deg;

int dfs(int cur, int prev){
    if(deg[cur]==1)return a[cur];
    ll sigma = 0;
    int maxC = 0;
    for(auto e:G[cur]){
        if(e==prev)continue;
        int res = dfs(e,cur);
        maxC = max(maxC,res);
        sigma+=res;
    }
    
    int t = 2*a[cur] - sigma;
    if( t<0 || t>a[cur] || sigma-t > 2*min(sigma-maxC,sigma/2) )throw -1;
    
    return t;
}

int main(){
    int n;
    cin>>n;
    rep(i,n)cin>>a[i];
    
    deg.resize(n,0);
    rep(i,n-1){
        int s,t;
        cin>>s>>t;
        s--,t--;
        deg[s]++;
        deg[t]++;
        G[s].pb(t);
        G[t].pb(s);
    }
    
    if(n==2){
        if(a[0]==a[1])cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        return 0;
    }
    
    int root = 0;
    while(deg[root]==1)root++;
    
    int res;
    try{
        res = dfs(root,-1);
    }catch(int e){
        cout<<"NO"<<endl;
        return 0;
    }
    if(res==0){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}