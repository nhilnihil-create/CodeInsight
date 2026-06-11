#include<iostream>
#include<queue>
#include<vector>
#define f first
#define s second
using namespace std;
vector<int>v[500005];
int visit[500005];
queue<int>q;
int n,a,b;
int main(){
	cin>>n;
	int m=n-1;
	while(m--){
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	q.push(1);
	q.push(1);
	q.push(n);
	q.push(2);
	while(!q.empty())
	{
		pair<int,int> now;
		now.f=q.front();q.pop();
		now.s=q.front();q.pop();
		if(visit[now.f])continue;
		visit[now.f]=now.s;
		for(int i=0;i<v[now.f].size();i++)
		{
			if(!visit[v[now.f][i]])
			{
				q.push(v[now.f][i]);
				q.push(now.s);
			}
		}
	}
	int black=0,white=0;
	for(int i=1;i<=n;i++){
		if(visit[i]==1)black++;
		else white++;
	}
	if(black>white)cout<<"Fennec\n";
	else cout<<"Snuke\n";
	return 0;
}