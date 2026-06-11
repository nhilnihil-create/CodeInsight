#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define pll pair < long , long >
#define vll vector < pll >
#define ml map < long , long >
#define mll map < pll , long >
#define x first
#define y second
#define vl vector < long >
#define io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
vl a[100005];
long g[100005]={0};
void dfs(long node , long par)
{
    long i;
    for(i=0;i<a[node].size();++i)
    if(a[node][i]!=par)
    {
        dfs(a[node][i],node);
        g[node]^=(g[a[node][i]]+1);
    }
}
int main()
{
    io
    long n,x,y,i;
    cin>>n;
    n--;
    while(n--)
    {
        cin>>x>>y;
        a[x].pb(y);
        a[y].pb(x);
    }
    dfs(1,-1);
    if(g[1]==0) cout<<"Bob";
    else cout<<"Alice";
    return 0;
}