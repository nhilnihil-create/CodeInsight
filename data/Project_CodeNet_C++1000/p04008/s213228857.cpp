#include "bits/stdc++.h"
#define ll long long
#define rep2(i,a,b) for(int i=a;i<=b;++i)
#define rep(i,n) for(int i=0;i<n;i++)
#define pii pair<int,int>
#define tii tuple<int,int,int>
#define pq priority_queue<int>
#define pqg priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define edge(v,a,b) v[a].pb(b);v[b].pb(a);
int MOD=1e9+7;
#define INF 2*1e9
#define N 310000 
using namespace std;
string alphabet("abcdefghijklmnopqrstuvwxyz");

int rnk[110000],ans,k;
vector<int> v[110000];
int p[110000];
int dfs(int a){
    int m=0;
    rep(i,v[a].size()){
        m=max(m,dfs(v[a][i]));
    }
    m++;
    if(m==k&&p[a]!=1){
        ans++; return 0;
    } 
    else{
        return m;
    }
}
main(){
    int n;
    ans=0;
    cin>>n>>k;
    int aaa;cin>>aaa;
    if(aaa!=1) ans++; 
    rep2(i,2,n){
        int a;
        cin>>a;
        v[a].pb(i);
        p[i]=a;
    }
    p[1]=1;
    dfs(1);
    cout<<ans;
    return 0;
}

