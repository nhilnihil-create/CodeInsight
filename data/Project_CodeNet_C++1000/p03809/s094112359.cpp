#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define pb emplace_back
typedef long long ll;
typedef pair<int,int> pint;

ll a[100001];
vector<int> g[100001];
ll dfs(int v,int p){
    ll sum=0,mx=0;
    rep(i,g[v].size()){
        if(g[v][i]==p) continue;
        if(g[g[v][i]].size()==1){
            sum+=a[g[v][i]];
            mx=max(a[g[v][i]],mx);
        }
        else{
            ll r=dfs(g[v][i],v);
            if(r==-1) return -1;
            else sum+=r;
            mx=max(mx,r);
        }
    }
    ll t=a[v]*2-sum;
    if(a[v]<mx||t<0||a[v]>sum) return -1;
    return t;
}
int main(){
    int n,ai,bi;
    cin>>n;
    rep(i,n) cin>>a[i];
    rep(i,n-1){
        cin>>ai>>bi;
        --ai,--bi;
        g[ai].pb(bi);g[bi].pb(ai);
    }
    if(n==2){
        if(a[0]==a[1]) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        return 0;
    }
    rep(i,n)if(g[i].size()>1){
        if(dfs(i,-1)==0){
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
        return 0;
    }
    return 0;
}