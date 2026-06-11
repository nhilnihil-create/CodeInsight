#include<bits/stdc++.h>
using namespace std;

#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)
#define F first
#define S second 

vector<int> v[100100];
stack<pair<int,pair<int,int> > > s;
int col[100100],le[100100];

main()
{
	int n,m,q;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		v[a].PB(b);
		v[b].PB(a);
	}
	scanf("%d",&q);
	for(int i=0;i<q;i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		s.push(MP(a,MP(b,c)));
	}
	while(!s.empty())
	{
		int nw=s.top().F;
		int d=s.top().S.F;
		int c=s.top().S.S;
		s.pop();
		queue<pair<int,pair<int,int> > > q;
		if(col[nw]!=0&&le[nw]<d)
			q.push(MP(nw,MP(d,c)));
		else if(col[nw]==0)
		{
			col[nw]=c;
			q.push(MP(nw,MP(d,c)));
		}
		while(!q.empty())
		{
			int po=q.front().F;
			int lf=q.front().S.F;
			int color=q.front().S.S;
			q.pop();
			//printf("%d %d %d|",po,lf,color);
			lf--;
			if(lf<0)
			{
				continue;
			}
			//printf("%d %d %d\n",po,lf,color);
			for(int i=0;i<v[po].size();i++)
			{
				int go=v[po][i];
				if(col[go]!=0&&le[go]<lf)
				{
					q.push(MP(go,MP(lf,color)));
					le[go]=lf;
				}
				else if(col[go]==0)
				{
					q.push(MP(go,MP(lf,color)));
					col[go]=color;
				}
			}
		}
	}
	for(int i=1;i<=n;i++)printf("%d\n",col[i]);
}