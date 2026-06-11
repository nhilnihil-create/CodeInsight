#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
const int nmax=100005;
vector<int> v[nmax];
int c[nmax];
int cate,bp,n,m,i,j,a,b;
long long iz,cc,nr_bp,ans;
void dfs(int x,int col)
{
    c[x]=col;cate++;
    for(int i=0;i<v[x].size();i++)
    {
        if(!c[v[x][i]])
          dfs(v[x][i],3-col);
        if(c[v[x][i]]==col)
          bp=0;
    }
}
int main()
{
    //freopen("data.in","r",stdin);
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int s=1;s<=n;s++)
        if(!c[s])
    {
        cate=0;bp=1;
        dfs(s,1);
        if(bp&&cate>1) nr_bp++;
        if(cate==1) iz++;
        else cc++;
    }
    ans=1LL*iz*n+n*iz-iz*iz;
    ans+=1LL*cc*cc+nr_bp*nr_bp;
    cout<<ans;
    return 0;
}