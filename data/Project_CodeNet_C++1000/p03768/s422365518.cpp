#include <iostream>
#include <vector>
using namespace std;
const int nmax=100005;
vector<int> v[nmax];
int viz[15][nmax];
int c[nmax],nod[nmax],dist[nmax],tip[nmax];
int n,m,q,i,x,y;
void memo(int col,int d,int x)
{
    if(viz[d][x]) return;
    viz[d][x]=1;
    if(d==0)
    {
        c[x]=col;
        return;
    }
    memo(col,d-1,x);
    for(int i=0;i<v[x].size();i++)
        memo(col,d-1,v[x][i]);
}
int main()
{
    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    cin>>q;
    for(i=1;i<=q;i++)
    {
        cin>>nod[i]>>dist[i]>>tip[i];
    }
    for(i=q;i>=1;i--)
    {
        memo(tip[i],dist[i],nod[i]);
    }
    for(i=1;i<=n;i++)
        cout<<c[i]<<'\n';
    return 0;
}
