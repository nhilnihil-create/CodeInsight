#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int d1[N],d2[N];
vector<int>e[N];
queue<int>q;
int main()
{
	int n,a,b,s1=0,s2=0;
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		e[a].push_back(b);
		e[b].push_back(a);
	}
	memset(d1,0x3f,sizeof(d1));
	d1[1]=0;
	q.push(1);
	while(!q.empty())
	{
		int k=q.front();
		q.pop();
		for(int i=0;i<e[k].size();i++)
		{
			if(d1[e[k][i]]>d1[k]+1)
			{
				d1[e[k][i]]=d1[k]+1;
				q.push(e[k][i]);
			}
		}
	}
	memset(d2,0x3f,sizeof(d2));
	d2[n]=0;
	q.push(n);
	while(!q.empty())
	{
		int k=q.front();
		q.pop();
		for(int i=0;i<e[k].size();i++)
		{
			if(d2[e[k][i]]>d2[k]+1)
			{
				d2[e[k][i]]=d2[k]+1;
				q.push(e[k][i]);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
  		if(d1[i]<=d2[i])
			s1++;
		else
			s2++;
	}
	if(s1>s2)
		puts("Fennec");
	else
		puts("Snuke");
	return 0;
}
