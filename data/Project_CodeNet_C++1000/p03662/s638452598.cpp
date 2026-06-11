#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll par[100009],vis[100009],vis2[100009];
vector<ll> v[100009];
void bfs(ll node,ll n)
{
    vis[node] = 1;
    for(ll i = 1;i<=n;i++)
        par[i] = -1;
    queue<ll> q;
    q.push(node);
    while(!q.empty())
    {
        ll temp = q.front();
        q.pop();

        if(temp==n)
            break;
        for(ll i=0;i<v[temp].size();i++)
        {
            if(vis[v[temp][i]]==0)
            {
                vis[v[temp][i]]= 1;
                q.push(v[temp][i]);
                par[v[temp][i]] = temp;
            }
        }
    }
}
ll bfs2(ll node)
{
    vis2[node] = 1;
    queue<ll> q;
    q.push(node);
    ll cnt = 1;
    while(!q.empty())
    {
        ll temp = q.front();
        q.pop();
        for(ll i=0;i<v[temp].size();i++)
        {
            if(vis2[v[temp][i]]==0)
            {
                cnt++;
                vis2[v[temp][i]]= 1;
                q.push(v[temp][i]);
            }
        }
    }
    return cnt;
}
vector<ll> p;
void path(ll n)
{

    if(n==-1)
        return;
    path(par[n]);
    p.push_back(n);
}
int main()
{
    ll i,n,j,x,y;
    cin>>n;
    for(i=0;i<n-1;i++)
    {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);

    }
    bfs(1,n);
    path(n);
    vector<ll> v1,v2;
    for(i=0,j=p.size()-1;i<=j;i++,j--)
    {
        v1.push_back(p[i]);
        v2.push_back(p[j]);
        vis2[p[i]] = 1;
        vis2[p[j]] = 2;
    }
    ll pq = 0;

    for(i=0;i<v1.size();i++)
    {
        pq+= bfs2(v1[i]);
    }
    if(pq<=n-pq)
    {
        cout<<"Snuke"<<endl;
    }
    else cout<<"Fennec"<<endl;



}
