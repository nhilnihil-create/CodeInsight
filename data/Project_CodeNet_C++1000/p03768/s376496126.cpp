#include <bits/stdc++.h>
using namespace std;
int n,m,q;
vector <int> g[100004];
int juv[100004];
int col[100004],qu;
void bfs(int s1,int d1,int c1){
	queue <pair<int,int> > q;
	q.push(make_pair(s1,0)); 
	while (!q.empty()){
		pair<int,int> x=q.front();
		q.pop();
		if (x.second!=d1 && d1-x.second<=juv[x.first]) continue;
		else juv[x.first]=d1-x.second;
		if (col[x.first]>0);
		else col[x.first]=c1;
		if (x.second>=d1) continue;
		else for (int i=0;i<g[x.first].size();i++)
			q.push(make_pair(g[x.first][i],x.second+1));  
	}
}
int s[100004],d[100004],c[100004];
int main(){
	memset (col,0,sizeof(col)); 
	cin>>n>>m;
	for (int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	cin>>q;
	for (int i=0;i<q;i++) cin>>s[i]>>d[i]>>c[i];
	reverse (s,s+q);
	reverse (d,d+q);
	reverse (c,c+q);
	for (int i=0;i<q;i++) bfs (s[i],d[i],c[i]);
	for (int i=1;i<=n;i++) cout<<col[i]<<endl;
	return 0;
}