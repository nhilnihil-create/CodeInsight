#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int v;
	edge *next;
}*h[2333],pool[5555];
int top;
inline void addedge(int u,int v)
{
	edge *tmp=&pool[top++];tmp->v=v;tmp->next=h[u];h[u]=tmp;
	edge *pmt=&pool[top++];pmt->v=u;pmt->next=h[v];h[v]=pmt;
}
int n,k;
int vis[2333],dis[2333];
queue<int> q;
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>k;
	int x,y;
	for(int i=1;i<n;i++)cin>>x>>y,addedge(x,y);
	int ans=0;
	if(k%2)
	{
		for(int i=1;i<=n;i++)
		{
			for(edge *tmq=h[i];tmq;tmq=tmq->next)
			{
				memset(vis,0,sizeof(vis));
				memset(dis,0,sizeof(dis));
				vis[i]=vis[tmq->v]=1;
				dis[i]=dis[tmq->v]=0;
				q.push(i);
				q.push(tmq->v);
				int cnt=0;
				while(!q.empty())
				{
					int u=q.front();q.pop();
					cnt++;
					if(dis[u]>=k/2)continue;
					for(edge *tmp=h[u];tmp;tmp=tmp->next)
					{
						if(!vis[tmp->v])
						{
							dis[tmp->v]=dis[u]+1;
							vis[tmp->v]=1;
							q.push(tmp->v);
						}
					}
				}
				if(cnt>ans)ans=cnt;
			}
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			memset(vis,0,sizeof(vis));
			memset(dis,0,sizeof(dis));
			vis[i]=1;
			dis[i]=0;
			q.push(i);
			int cnt=0;
			while(!q.empty())
			{
				int u=q.front();q.pop();
				cnt++;
				if(dis[u]>=k/2)continue;
				for(edge *tmp=h[u];tmp;tmp=tmp->next)
				{
					if(!vis[tmp->v])
					{
						dis[tmp->v]=dis[u]+1;
						vis[tmp->v]=1;
						q.push(tmp->v);
					}
				}
			}
			if(cnt>ans)ans=cnt;
		}
	}
	cout<<n-ans<<endl;
	return 0;
}