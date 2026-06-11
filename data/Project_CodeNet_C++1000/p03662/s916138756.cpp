#include <bits/stdc++.h>
using namespace std;
int n;
vector<int>g[100001];
int main(){
	cin>>n;
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	vector<int>col(n+1);
	queue<int>q;
	q.push(1);
	q.push(n);
	col[1]=1;
	col[n]=2;
	int f,s;
	f=s=1;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=0;i<g[x].size();i++){
			int y=g[x][i];
			if(col[y]==0){
				q.push(y);
				col[y]=col[x];
				if(col[y]==1)f++;
				else s++;
			}
		}
	}
	if(f>s)cout<<"Fennec";
	else cout<<"Snuke";
	return 0;
}
