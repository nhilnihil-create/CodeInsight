#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
#include<vector>
#define maxn 200005
using namespace std;
struct nod
{
	int now,dis;
	nod(int x,int y)
	{
		now=x;
		dis=y;
	}
	nod(){}
};
bool operator<(nod a,nod b)
{
	return a.dis>b.dis;
}
int n,ss,t,tot[2];
int pre[maxn];
char s[maxn];
int head[2][maxn],nex[2][maxn*30],to[2][maxn*30],vis[maxn];
void add(int f,int x,int y)
{
	to[f][++tot[f]]=y; nex[f][tot[f]]=head[f][x]; head[f][x]=tot[f];
}
int pre2[maxn][30],id[maxn];
int dis1[maxn],dis2[maxn];
priority_queue<nod> q;
vector<nod>edge[maxn];
void spfa(int start,int f,int *dis)
{
	memset(dis,0x3f,sizeof(int)*maxn);
	memset(vis,0,sizeof(vis));

	dis[start]=0;
	q.push(nod(start,0));
	while(!q.empty())
	{
	//	cerr<<"+1"<<endl;
		int now=q.top().now; q.pop();
		if(vis[now]) continue;
		vis[now]=1;
	//	cout<<now<<" "<<dis[now]<<endl;
		for(int i=head[f][now];i;i=nex[f][i])
		{
			if(dis[to[f][i]]>dis[now]+1)
			{
				dis[to[f][i]]=dis[now]+1;
				q.push(nod(to[f][i],dis[to[f][i]]));
			}
		}
	}
}
int cmp(int i,int j)
{
	return dis1[i]<dis1[j];
}
int can[30];
int vis1[maxn];
int main()
{
	scanf("%s",s+1); n=strlen(s+1);

	int ss=n+1,t=n+2;

	for(int i=0;i<=25;i++)
		pre[i]=ss;

	for(int i=1;i<=n;i++)
	{
		id[i]=i;
		for(int j=0;j<=25;j++)
		if(!vis[pre[j]])
		{
			add(0,pre[j],i);
			add(1,i,pre[j]);
			vis[pre[j]]=1;
			edge[pre[j]].push_back(nod(i,j));
		}

		for(int j=0;j<=25;j++)
			vis[pre[j]]=0,pre2[i][j]=pre[j];

		pre[s[i]-'a']=i;
	}

	for(int i=0;i<=25;i++)
		if(!vis[pre[i]])
			add(0,pre[i],t),add(1,t,pre[i]),vis[pre[i]]=1,edge[pre[i]].push_back(nod(t,i));
	for(int i=0;i<=25;i++)
		vis[pre[i]]=0,pre2[t][i]=pre[i];

	spfa(ss,0,dis1);
	spfa(t,1,dis2);

	int res=dis1[t];

	int now=1;


	sort(id+1,id+1+n,cmp);

	int preans=0;

	vis1[ss]=1;
	for(int i=1;i<=n;i++)
	{
		if(now==res) 
			break;

		int temp=i;

		int p=id[i];
		while(dis1[p]==now)
		{
			for(int j=0;j<=25;j++)
			{
				if(dis1[p]+dis2[p]==res && dis1[p]==dis1[pre2[p][j]]+1 && vis1[pre2[p][j]])
					can[j]=1;
			}
			i++;
			p=id[i];
		}
	

		for(int j=0;j<=25;j++)
		if(can[j])
		{
			printf("%c",'a'+j);
			preans=j;
			break;
		}

		for(int j=temp;j<=i-1;j++)
		{
			p=id[j];
//			cerr<<dis1[p]<<" ";
			if(dis1[p]+dis2[p]==res && dis1[p]==dis1[pre2[p][preans]]+1 && vis1[pre2[p][preans]])
				vis1[p]=1;
		}

		memset(can,0,sizeof(can));
		i--;

		now++;
	}

	for(int i=0;i<=25;i++)
	{
		if(dis1[t]==dis1[pre2[t][i]]+1 && vis1[pre2[t][i]])
			return printf("%c\n",'a'+i),0;
	}
}
