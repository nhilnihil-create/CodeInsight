#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
#define N 100010
vector<int> V[N];
queue<int> Q;
bool vis[N];
int dis_from_1[N];
int dis_from_n[N];
int n;
void BFS(int start,bool mode)
{
    while(!Q.empty()) Q.pop();
    Q.push(start);
    memset(vis,0,sizeof(vis));
    vis[start]=1;
    if(mode) dis_from_1[start]=0;
    else dis_from_n[start]=0;
    while(!Q.empty())
    {
        int now=Q.front();
        Q.pop();
        for(int i=0;i<V[now].size();i++)
        {
            int next=V[now][i];
            if(mode)    dis_from_1[next]=dis_from_1[now]+1;
            else        dis_from_n[next]=dis_from_n[now]+1;
            if(!vis[next])
            {
                vis[next]=1;
                Q.push(next);
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n)
    {
        for(int i=1;i<=n;i++) V[i].clear();
        int a,b;
        for(int i=1;i<=n-1;i++)
        {
            cin>>a>>b;
            V[a].push_back(b);
            V[b].push_back(a);
        }//成图
        //分别从1,N BFS比较距离
        BFS(1,true);
        BFS(n,false);
        int first_num=0;
        int second_num=0;
        for(int i=1;i<=n;i++)
        {
            if(dis_from_1[i]<=dis_from_n[i]) first_num++;
            else second_num++;
        }
        if(first_num>second_num) cout<<"Fennec"<<endl;
        else cout<<"Snuke"<<endl;
    }
}