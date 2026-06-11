#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxx = 1e5+10;
vector<int> v[maxx];
int cnt = 0;
int a[maxx],b[maxx];
void dfs(int x,int y)
{
    if(a[x])
        return ;
    a[x]=y;
    for(int i=0;i<v[x].size();i++)
        dfs(v[x][i],y+1);
}
void dfs2(int x,int y)
{
    if(b[x])
        return ;
    b[x]=y;
    for(int i=0;i<v[x].size();i++)
        dfs2(v[x][i],y+1);
}
int main()
{
    int n,x,y;
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        scanf("%d%d",&x,&y);
        v[x].push_back(y),v[y].push_back(x);
    }
    dfs(1,1);
    dfs2(n,1);
    int cnt1 = 0,cnt2 = 0;
    for(int i=1;i<=n;i++){
        if(a[i] <= b[i])
            cnt1++;
        else
            cnt2++;
    }
    //cout<<cnt1<<" "<<cnt2<<endl;
    if(cnt1 - cnt2 > 0)
        cout<<"Fennec\n";
    else
        cout<<"Snuke\n";
    return 0;
}
