#include <bits/stdc++.h>
using namespace std;
int dist1[200009],dist2[200009],n,a,b;
vector<int>x[200009];
void dfs1(int pos,int depth)
{
    
    if(dist1[pos]!=-1) return;
    dist1[pos]=depth;
    for(int i=0; i<x[pos].size(); i++) dfs1(x[pos][i],depth+1);
}
void dfs2(int pos,int depth)
{
    
    if(dist2[pos]!=-1) return;
    dist2[pos]=depth;
    for(int i=0; i<x[pos].size(); i++) dfs2(x[pos][i],depth+1);
}
int main()
{
    cin>>n;
    for(int i=0; i<n-1; i++)
    {
        cin>>a>>b;
        x[a].push_back(b);
        x[b].push_back(a);
    }
    for(int i=0; i<200009; i++)
    {
        dist1[i]=-1;
        dist2[i]=-1;
    }
    dfs1(1,0);
    dfs2(n,0);
    int cnt1=0,cnt2=0;
    for(int i=1; i<=n; i++)
    {
        if(dist1[i]<=dist2[i]) cnt1++;
        else cnt2++;
    }
    if(cnt1>cnt2) cout<<"Fennec"<<endl;
    else cout<<"Snuke"<<endl;
    
    return 0;
}