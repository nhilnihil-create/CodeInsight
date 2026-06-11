#include <bits/stdc++.h>
using namespace std;
 
int n;
vector<int> G[100010];
int d[2][100010];

void dist(int s,int* ret) {
	for(int i=1;i<=n;i++)ret[i]=-1;
	queue<int> que;
	ret[s]=0;
	que.push(s);
	while(!que.empty()){
		int v=que.front(); que.pop();
		for(int u: G[v]){
			if(ret[u]==-1){
				ret[u]=ret[v]+1;
				que.push(u);
			}
		}
	}
}
 
int main(){
	scanf("%d",&n);
	for(int i=0;i<n-1;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	
	dist(1,d[0]);
	dist(n,d[1]);
	int s=1,t=n;
	while(1){
		for(int u: G[s]){
			if(d[1][u]<d[1][s]){
				s=u;
				break;
			}
		}
		if(s==t){
			for(int u: G[s]){
				if(d[0][u]<d[0][s]){
					s=u;
					break;
				}
			}
			break;
		}
		for(int u: G[t]){
			if(d[0][u]<d[0][t]){
				t=u;
				break;
			}
		}
		if(s==t){
			for(int u: G[t]){
				if(d[1][u]<d[1][t]){
					t=u;
					break;
				}
			}
			break;
		}
	}
	dist(s,d[0]);
	dist(t,d[1]);
	s=t=0;
	for(int i=1;i<=n;i++){
		if(d[0][i]<d[1][i])s++;
		else t++;
	}
	if(s>t)puts("Fennec");
	else puts("Snuke");
}