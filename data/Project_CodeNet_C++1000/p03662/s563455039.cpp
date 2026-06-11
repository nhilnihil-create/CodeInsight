#include<iostream>
#include<queue>
#include<vector>
#define f first
#define s second
using namespace std;
vector<int>v[500005];
int visit[3][500005];
queue<int>q;
int n,a,b;
inline void BFS(int k,int o){
	q.push(k);
	q.push(1);
	while(!q.empty()){
		int x=q.front();q.pop();
		int t=q.front();q.pop();
		visit[o][x]=t;
		for(int i=0;i<v[x].size();i++){
			if(visit[o][v[x][i]]==0)
			q.push(v[x][i]),q.push(t+1);
		}
	}
}
int main(){
	cin>>n;
	int m=n-1;
	while(m--){
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	BFS(1,1);
	BFS(n,2);
	int x1,x2;
	x1=x2=0;
	for(int i=1;i<=n;i++){
	//	cout<<visit[1][i]<<' '<<visit[2][i]<<endl;
		if(visit[1][i]<=visit[2][i])x1++;
		else x2++;
	}
	if(x1>x2)cout<<"Fennec\n";
	else cout<<"Snuke\n";
	return 0;
}