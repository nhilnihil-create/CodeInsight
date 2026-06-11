#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push

int n;
vector<int> edges[200001];

void bfs(int t,vector<int> &v){
	queue<int> q;
	vector<int> dist(n,1e9);
	dist[t]=0;
	v[t]=0;
	q.pb(t);
	while (!q.empty()){
		int x=q.front();
		q.pop();
		
		for (int j=0;j<edges[x].size();j++){
			int i=edges[x][j];
			if (dist[i]==1e9){
				q.pb(i);
				dist[i]=dist[x]+1;
				v[i]=v[x]+1;
			}
		}
	}
}

int main(){
	cin>>n;
	vector<int> f(n);
	vector<int> s(n);
	for (int i=0;i+1<n;i++){
		int a,b;
		cin>>a>>b;
		a--;
		b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	bfs(0,f);
	bfs(n-1,s);
	int cnt=0;
	for (int i=0;i<n;i++)
		if (f[i]<=s[i])
			cnt++;
	cout<<(cnt>n-cnt ? "Fennec" : "Snuke")<<endl;
	return 0;
}