#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int a[N];
vector<int> v[N];
void dfs(int x, int par=0)
{
    for(int i=0;i<v[x].size();i++)
    {
        if(v[x][i]==par)
            continue;
        dfs(v[x][i],x);
        a[x]^=(a[v[x][i]]+1);
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1);
    if(a[1])
        cout<<"Alice"<<endl;
    else
        cout<<"Bob"<<endl;
    return 0;
}
