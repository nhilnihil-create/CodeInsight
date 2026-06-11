#include<iostream>
#include<map>
#include<list>
#include<queue>
#include<climits>
using namespace std;
class graph
{
    map<int,list<int>>l;
public:
    void add(int x,int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void bfs(int src,int n)
    {
        map<int,int>visited;
        queue<int>q;
        int c=0;
        for(auto i:l)
        {
            visited[i.first]=INT_MAX;
        }
        q.push(src);
        visited[src]=0;
        while(!q.empty())
        {
            int t=q.front();

            q.pop();
            for(auto i:l[t])
            {
                if(visited[i]==INT_MAX)
                {
                    visited[i]=visited[t]+1;
                    q.push(i);
                }
            }
        }
        for(auto i:visited)
        {
            if(i.second==2&&i.first==n)
            {
                c++;
                cout<<"POSSIBLE"<<endl;
            }
        }
        if(c==0)
        {
            cout<<"IMPOSSIBLE"<<endl;
        }
    }
};
int main()
{
    graph g;
    int n,m,a,b;
    cin>>n>>m;
    while(m--)
    {
        cin>>a>>b;
        g.add(a,b);
    }
    g.bfs(1,n);
    return 0;
}
