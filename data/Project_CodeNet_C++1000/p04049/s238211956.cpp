#include<bits/stdc++.h>
#define pb push_back
using namespace std;
struct node{
	int x;
	int y;
};
bool visit[2001];
int times;
int n;
int k;
node p[2001];
vector<int> can[2001];
int work1(int mp)
{
	int tot=0;
	queue<node> q;
	node start;
	start.x=mp;
	start.y=0;
	q.push(start);
	visit[mp]=0;
	while(!q.empty())
	{
		node now=q.front();
		q.pop();
		for(int i=0;i<can[now.x].size();i++)
		{
			int ok=can[now.x][i];
			if(visit[ok])
			{
				node next;
				next.x=ok;
				next.y=now.y+1;
				q.push(next);
				if(next.y>k/2)
				{
					tot++;
				}
				visit[ok]=0;
			}
		}
	}
	return tot;
}
inline int work2(int mp1,int mp2,int str)
{
	int tot=0;
	queue<node> q;
	node start;
	start.x=mp1;
	start.y=0;
	q.push(start);
	visit[mp1]=0;
	visit[mp2]=0;
	while(!q.empty())
	{
		node now=q.front();
		q.pop();
		for(int i=0;i<can[now.x].size();i++)
		{
			int ok=can[now.x][i];
			if(visit[ok])
			{
				node next;
				next.x=ok;
				next.y=now.y+1;
				q.push(next);
				if(next.y>(k-1)/2)
				{
					tot++;
				}
				visit[ok]=0;
			}
		}
	}
	start.x=mp2;
	start.y=0;
	q.push(start);
	while(!q.empty())
	{
		node now=q.front();
		q.pop();
		for(int i=0;i<can[now.x].size();i++)
		{
			int ok=can[now.x][i];
			if(visit[ok])
			{
				node next;
				next.x=ok;
				next.y=now.y+1;
				q.push(next);
				if(next.y>(k-1)/2)
				{
					tot++;
				}
				visit[ok]=0;
			}
		}
	}
	return tot;
}
int main()
{
//	freopen("some.txt","r",stdin);
	cin>>n>>k;
	for(int i=1;i<=n-1;i++)
	{
		cin>>p[i].x>>p[i].y;
		can[p[i].x].pb(p[i].y);
		can[p[i].y].pb(p[i].x);
	}
	int cnt=1<<30;
	if(k%2==0)
	{
		for(int i=1;i<=n;i++)
		{
			memset(visit,1,sizeof(visit));
			cnt=min(work1(i),cnt);
		}
	}
	else
	{
		for(int i=1;i<=n-1;i++)
		{
//			times++;
			memset(visit,1,sizeof(visit));
			cnt=min(work2(p[i].x,p[i].y,i),cnt);
		}
	}
	cout<<cnt<<endl;
	//cout<<times<<endl;
	return 0;
}