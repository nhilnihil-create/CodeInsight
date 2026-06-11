#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,a,b,ans1,ans2;
vector<ll>ar[100005];
ll visit[100005];

ll bfs(ll s,ll p)
{
    visit[s]=1;
    visit[p]=2;
    queue<ll>q;
    q.push(s);
    q.push(p);

    while(!q.empty())
    {
        ll x = q.front();
        q.pop();
        if(visit[x]==1)
            ans1++;
        else ans2++;

        for(int i=0;i<ar[x].size();i++)
        {
            if(visit[ar[x][i] ]==0)
            {
                q.push(ar[x][i]);
                visit[ar[x][i] ]=visit[x];
            }
        }
    }
}

int main()
{
    cin>>n;
    for(int i=1;i<n;i++)
    {
        cin>>a>>b;
        ar[a].push_back(b);
        ar[b].push_back(a);
    }
    memset(visit,0,sizeof(visit));
    bfs(1,n);
    if(ans1>ans2) cout<<"Fennec\n";
    else cout<<"Snuke\n";
}
