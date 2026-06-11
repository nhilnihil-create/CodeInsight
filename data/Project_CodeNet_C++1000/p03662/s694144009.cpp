#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
#define N 100005
int vis[N],n;
vector<int>g[N];
int main()
{
	int i, x, y, index, cnt=0, now;
	pair<int,int> cur;
	scanf("%d",&n);
	for(i=0;i<n-1;++i)
	{
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	queue<pair<int,int> >qu1;
	queue<pair<int,int> >qun;
	qu1.push(make_pair(1,0)); vis[1]=1;
	qun.push(make_pair(n,0)); vis[n]=2;

	while(!qu1.empty()||!qun.empty())
	{
		if(!qu1.empty()){
			cur=qu1.front();
			index=cur.second;
			while(cur.second==index){
				for(i=0;i<g[cur.first].size();++i)
				{
					now=g[cur.first][i];
					if(vis[now]) continue;
					vis[now]=1;
					qu1.push(make_pair(now,index+1));
				}
				qu1.pop();
				if(qu1.empty()) break;
				cur=qu1.front();
			}
		}
		
		if(!qun.empty()){
			cur=qun.front();
			index=cur.second;
			while(cur.second==index){
				for(i=0;i<g[cur.first].size();++i)
				{
					now=g[cur.first][i];
					if(vis[now]) continue;
					vis[now]=2;
					qun.push(make_pair(now,index+1));
				}
				qun.pop();
				if(qun.empty()) break;
				cur=qun.front();
			}
		}
	}
	
	for(i=2;i<n;++i)
	{
		if(vis[i]==1) 
			cnt++;
		else 
			cnt--;
	}

	if(cnt>0)
	cout<<"Fennec";
	else
	cout<<"Snuke";
	
	return 0;
}