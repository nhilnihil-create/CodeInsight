#include <bits/stdc++.h>
using namespace std;
int N,M;
vector <bool> WFS(int t, vector <vector <pair<long long,long long>>> edge);
int main()
{
    cin >> N >> M;
    vector <vector <pair<long long,long long>>> edge(N+1);
    long long a,b,c;
    vector <vector<long long>> opt(N+1,vector<long long> (N+1));
    for (int i=0;i<M;i++)
    {
        cin >> a >> b >> c;
        edge[b].push_back(make_pair(a,-c));
    } 
    for (int i=1;i<N+1;i++) opt[0][i]=LONG_MAX/3*2;
    opt[0][1]=0;
    for (int i=1;i<N+1;i++)
    {
        for (int v=1;v<N+1;v++)
        {
            opt[i][v]=opt[i-1][v];
            for (int u=0;u<edge[v].size();u++)
            {
                opt[i][v]=min({opt[i-1][v],opt[i-1][edge[v][u].first]+edge[v][u].second,opt[i][v]});
            }
        }
    }
    vector <bool> visit;
    visit=WFS(N,edge);
    bool can=true;
    for (int i=1;i<N+1;i++)
    {
        if (visit[i])
        {
            if (opt[N][i]!=opt[N-1][i]) 
            {
                cout << "inf" << endl;
                can=false;
                break;
            } 
        }
    }
    if (can) cout << -opt[N][N] << endl;
return 0;
}

vector <bool> WFS(int t, vector <vector <pair<long long,long long>>> edge)
{
    vector <bool> visit(N+1);
    visit[0]=true;
    vector <int> que;
    que.push_back(t);
    for (int i=0;i<N+1;i++)
    {
        visit[i]=false;
    }
    int v;
    while (!que.empty())
    {
        v=que.front();
        que.erase(que.begin());
        for (int u=0;u<edge[v].size();u++)
        {
            if (!visit[edge[v][u].first])
            {
                visit[edge[v][u].first]=true;
                que.push_back(edge[v][u].first);
            }
        }
    }
return visit;
}