#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n,x,y;
vector <int> v[100005];
long long d[100005]={0},t[100005]={0};
const int INF=1000000005;
int main()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(int i=1;i<=n;i++)
	    d[i]=INF;
	d[1]=0;
	queue <int> q;
	q.push(1);
	while(q.size())
	{
		int u=q.front();q.pop();
		for(int i=0;i<v[u].size();i++)
		{
			int f=v[u][i];
			if(d[f]>d[u]+1)
			{
				d[f]=d[u]+1;
			    q.push(f);
			}    
		}
	}
	//for(int i=1;i<=n;i++)
	    //cout<<i<<' '<<d[i]<<endl;
	for(int i=1;i<=n;i++)
	    t[i]=INF;
	t[n]=0;
	queue <int> qu;
	qu.push(n);
	while(qu.size())
	{
		int u=qu.front();qu.pop();
		for(int i=0;i<v[u].size();i++)
		{
			int f=v[u][i];
			if(t[f]>t[u]+1)
			{
				t[f]=t[u]+1;
			    qu.push(f);
			}    
		}
	}
	//for(int i=1;i<=n;i++)
	    //cout<<i<<' '<<t[i]<<endl;
	int f=0,s=0,e=0;
	for(int i=1;i<=n;i++)
	{
		//cout<<i<<' '<<d[i]<<' '<<t[i]<<endl;
		if(d[i]<t[i])
		    f++;
		if(d[i]>t[i])
		    s++;
		if(d[i]==t[i])
		    e++;
	}
	f+=e;
	//cout<<f<<' '<<s<<' '<<e<<endl;
	if(f>s)
	    cout<<"Fennec";
	else
	    cout<<"Snuke";
	return 0;
}