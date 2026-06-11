#include<bits/stdc++.h>
using namespace std;

vector<int> v[100100];
int area[2];
stack<int> path;
int dif,n;

int fi_ano(int nw,int pa,int walk)
{
	if(nw==n)
	{
		dif=walk-1;
		return n;
	}
	int ck=-1,re=-1;
	for(int i=0;i<v[nw].size();i++)
	{
		if(v[nw][i]==pa)continue;
		ck=fi_ano(v[nw][i],nw,walk+1);
		if(ck==n)
		{
			path.push(nw);
			re=n;
		}
	}
	return re;
}

void cut(int nw,int pa,int team)
{
	area[team]++;
	for(int i=0;i<v[nw].size();i++)
	{
		if(v[nw][i]==pa)continue;
		cut(v[nw][i],nw,team);
	}
	return ;
}

main()
{
	scanf("%d",&n);
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	fi_ano(1,-1,0);
	int si=0,bf=path.top(),ti=0;
	path.pop();
	for(int i=0;i<v[1].size();i++)
	{
		if(!path.empty()&&v[1][i]==path.top())continue;
		if(v[1][i]==n)continue;
		cut(v[1][i],1,0);
	}
	int spfu=0;
	if(dif%2==1)spfu=1;
	//printf("area1:%d\n",area[0]);
	while(!path.empty())
	{
		int prebf=path.top();
		//printf("nw:%d\n",prebf);
		si++;
		path.pop();
		if(si>(dif/2)+spfu)ti=1;
		area[ti]++;
		for(int i=0;i<v[prebf].size();i++)
		{
			if(v[prebf][i]==bf||v[prebf][i]==1||v[prebf][i]==n)continue;
			if(!path.empty()&&v[prebf][i]==path.top())continue;
			//printf("spgo:%d tm:%d\n",v[prebf][i],ti);
			cut(v[prebf][i],prebf,ti);
		}
		bf=prebf;
	}
	for(int i=0;i<v[n].size();i++)
	{
		if(v[n][i]==bf)continue;
		if(v[n][i]==1)continue;
		cut(v[n][i],n,1);
	}
	//printf("%d %d\n",area[0],area[1]);
	if(area[0]>area[1])printf("Fennec\n");
	else printf("Snuke\n");
}
/*
6
1 2
2 3
3 4
3 5
5 6
9
1 2
2 3
2 4
4 5
2 6
6 7
6 8
6 9 
*/