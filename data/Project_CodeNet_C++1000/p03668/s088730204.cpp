#include <iostream>
#include <vector>
using namespace std;
const int nmax=100005;
vector<int> v[nmax];
int viz[nmax],sg[nmax];
int n,i,a,b;
void dfs(int x)
{
    viz[x]=1;
    for(int i=0;i<v[x].size();i++)
        if(!viz[v[x][i]])
    {
        dfs(v[x][i]);
        sg[x]^=(sg[v[x][i]]+1);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(i=1;i<=n-1;i++)
    {
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1);
    if(sg[1]) cout<<"Alice";
    else cout<<"Bob";
    return 0;
}