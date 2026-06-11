#include<bits/stdc++.h>
#define int long long
#define vi vector<int>
#define pb push_back
#define log(x,b) (log(b)/log(x))
#define rep(i,x,y) for(int i=(x);i<(y);i++)
using namespace std;
const int mod=1e9+7;
vector<int>graph[50];
int32_t main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    vi res(n+1);
    for(int i=1;i<=n;i++){
        res[i]+=graph[i].size();
    }
    rep(i,1,n+1)cout<<res[i]<<endl;

    return 0;
}
