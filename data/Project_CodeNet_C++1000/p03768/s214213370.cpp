#include<bits/stdc++.h>

using namespace std;
int input[100005][11];
int ma[100005],an[100005];
int bfs[100005];
vector<int>edge[100005];
void go(int in[]){
	int x=in[0]-1;
	int d=in[1];
	int v=in[2];
	if(d<=ma[x])return;
	ma[x]=d;
	bfs[0]=x;
	int rr=1;
	for(int i=0;i<rr;i++){
		int x=bfs[i];
		if(!an[x])an[x]=v;
		if(!ma[x])continue;
		for(int j=0;j<edge[x].size();j++){
			int y=edge[x][j];
			int nd=ma[x]-1;
			if(nd>ma[y]){
				ma[y]=nd;
				bfs[rr++]=y;
			}
		}
	}
} 
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		x--;y--;
		edge[x].push_back(y);
		edge[y].push_back(x); 
	}
	int q;
	cin>>q;
	for(int i=0;i<q;i++)for(int j=0;j<3;j++)cin>>input[i][j];
	memset(ma,-1,sizeof(ma));
	for(int i=q-1;i>=0;i--){
		go(input[i]);
	}
	for(int i=0;i<n;i++)cout<<an[i]<<endl;
	return 0;
}