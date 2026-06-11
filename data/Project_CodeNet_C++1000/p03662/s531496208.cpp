#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#define MAX 100005 
using namespace std;

struct node1
{
	int parent;
	vector<int> a;//相邻之节点 
};

node1 pnt[MAX];
int n;
int main()
{
	int i,j;
	int x,y;
	int f,t;
	int dis;
	int c;
	int fenneccontrol=0;
	int snukecontrol=0;
	queue<int> q;
	queue<int> q1;
	cin>>n;
	for (i=1;i<n;i++)
	{
		cin>>x>>y;
		pnt[x].a.push_back(y);
		pnt[y].a.push_back(x);
	}
	pnt[1].parent=-1;
	q.push(1);
	while (!q.empty())
	{
		f=q.front();
		q.pop();
		for (i=0;i<pnt[f].a.size();i++)
		{
			t=pnt[f].a[i];
			if (t==pnt[f].parent) continue;
			pnt[t].parent=f;
			q.push(t);
		}
	}
	
	f=n;
	dis=0;
	while(f!=1)
	{
		dis++;
		f=pnt[f].parent;
	}
	
	dis--;
	c=n;
	
	for (i=1;i<=dis/2;i++)
	{
		c=pnt[c].parent;
	}
	
	
	q1.push(c);
	while (!q1.empty())
	{
		f=q1.front();
		q1.pop();
		for (i=0;i<pnt[f].a.size();i++)
		{
			t=pnt[f].a[i];
			if (t==pnt[f].parent) continue;
			snukecontrol++;
			q1.push(t);
		}
	}
	
	snukecontrol++;
	fenneccontrol=n-snukecontrol;
	if (snukecontrol>=fenneccontrol)
	{
		cout<<"Snuke";
	}
	else
	{
		cout<<"Fennec";
	}
	return 0;
}