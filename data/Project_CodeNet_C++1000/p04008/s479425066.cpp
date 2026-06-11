#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(),v.end()
#define pb push_back
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);

vector<int> G[100005];
int ans,k,arr[100005];

int dfs(int u)
{
    int h=1;
    for(int v:G[u])
        h=max(h,dfs(v)+1);
    if(h>=k&&arr[u]!=1)
        ++ans,arr[u]=1,h=0;
    return h;
}

int main()
{
    IOS();
    int n;
    cin >> n >> k;
    for(int i=1;i<=n;++i)
        cin >> arr[i];
    if(arr[1]!=1) ++ans,arr[1]=1;
    for(int i=2;i<=n;++i)
        G[arr[i]].pb(i);
    dfs(1);
    cout << ans << "\n";
}