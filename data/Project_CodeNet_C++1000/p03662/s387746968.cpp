#include<iostream>
#include<queue>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
const int MAXN=100000+10;
vector<int> edge[MAXN];
int n,cnt[3];
int tree[MAXN];
void bfs()
{
    queue<int> q;
    q.push(1),q.push(n);
    while(!q.empty())
    {
        int temp=q.front();
        q.pop();
        cnt[tree[temp]]++;
        for(int i=0;i<edge[temp].size();++i)
        {
            int v=edge[temp][i];
            //cnt[tree[temp]]++;
            if(tree[v])continue;
            else tree[v]=tree[temp];
            q.push(v);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    memset(tree,0,sizeof(tree));
    cin>>n;
    for(int i=1;i<n;++i)
    {
        int x,y;
        cin>>x>>y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    tree[1]=1,tree[n]=2;
    bfs();
    if(cnt[2]>=cnt[1])
        cout<<"Snuke"<<endl;
    else
        cout<<"Fennec"<<endl;
    return 0;
}