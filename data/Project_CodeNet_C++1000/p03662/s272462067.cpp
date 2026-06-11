#include<bits/stdc++.h>
using namespace std;
vector<int> g[100010];
int clr[100010];
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	memset(clr,-1,sizeof(clr));
	clr[1]=1;clr[n]=2;
	queue<int> q;
	q.push(1);q.push(n);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=0;i<g[x].size();i++){
			if(clr[g[x][i]]==-1){
				q.push(g[x][i]);
				clr[g[x][i]]=clr[x];
			}
		}
	}
	int fennec=0,snuke=0;
	for(int i=1;i<=n;i++){
		if(clr[i]==1)fennec++;
		else snuke++;
	}
	if(fennec>snuke)cout<<"Fennec"<<endl;
	else cout<<"Snuke"<<endl;
	return 0;
}