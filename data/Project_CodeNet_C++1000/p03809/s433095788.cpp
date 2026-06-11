#include "bits/stdc++.h"
#define ll long long
#define rep2(i,a,b) for(int i=a;i<=b;++i)
#define rep(i,n) for(int i=0;i<n;i++)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define tii tuple<int,int,int>
#define pq priority_queue<int>
#define pqg priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define edge(v,a,b) v[a].pb(b);v[b].pb(a);
ll MOD=998244353;
#define INF 2*1e9
#define N 1000010
#define MAX_V 900010
using namespace std;

int n;
vector<int> G[N];
int a[N];
bool flag=true;
int dfs(int x,int p){
    int m=0,sum=0;
    rep(i,G[x].size()){
        if(G[x][i]==p)continue;
        int s=dfs(G[x][i],x);
        sum+=s;
        m=max(m,s);
    }
    if(p==0){
        if(G[1].size()==1){
            cout<<(sum==a[1]?"YES":"NO");
            return 0;
        }
        if(flag==false)cout<<"NO";
        else if(sum %2)cout<<"NO";
        else if(m*2>sum)cout<<"NO";
        else if(sum/2!=a[1])cout<<"NO";
        else cout<<"YES";
    }
    if(G[x].size()==1){
        return a[x];
    }
    if(sum<a[x]){
        flag=false;return 0;
    }
    else if(m>a[x]){
        flag=false;return 0;
    }
    else if(sum>a[x]*2){
        flag=false;return 0;
    }
    return a[x]*2-sum;
}
main(){
    cin>>n;
    rep2(i,1,n)cin>>a[i];
    rep(i,n-1){
        int c,d;cin>>c>>d;
        G[c].pb(d);G[d].pb(c);
    }
    dfs(1,0);
    return 0;
}