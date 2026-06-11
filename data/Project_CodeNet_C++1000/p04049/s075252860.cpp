#include<bits/stdc++.h>
using namespace std;
#define lint long long
#define inf 100000000000000000
#define mod 1000000007
#define MAX 1000005
#define pb push_back
#define mp make_pair
#define vit vector<int>::iterator
typedef pair<int,int> pii;
vector<int> V[MAX];
vector<pii> E;
int dfs(int u,int p,int d,int dmax){
    int sum=1;
    if(d==dmax)
        return sum;
    for(auto v:V[u]){
        if(v!=p){
            sum+=dfs(v,u,d+1,dmax);
        }
    }
    return sum;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,d;
    cin>>n>>d;
    if(d%2){
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            V[u].pb(v);
            V[v].pb(u);
            E.pb(mp(u,v));
        }
        int mx=0;
        for(auto e:E){
            int vlu=dfs(e.first,e.second,1,d/2+1);
            vlu+=dfs(e.second,e.first,1,d/2+1);
            mx=max(mx,vlu);
        }
        cout<<n-mx;
    }
    else{
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            V[u].pb(v);
            V[v].pb(u);
        }
        int mx=0;
        for(int i=1;i<=n;i++){
            int vlu=dfs(i,-1,0,d/2);
            mx=max(mx,vlu);
        }
        cout<<n-mx;
    }
}
/*
6 5
1 2
3 2
4 2
1 6
5 6
*/
