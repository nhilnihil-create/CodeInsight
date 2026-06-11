#include <bits/stdc++.h>
#define LL long long
#define mp make_pair
#define pb push_back
#define INF (1<<29)
using namespace std;
typedef pair<int,int>pii;
int n;
vector<int>G[100010];
int main(){
	cin>>n;
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		G[x].pb(y);
		G[y].pb(x);
	}
	vector<int>color(n+10,-1);
	queue<int>qq;
	qq.push(1);
	qq.push(n);
	color[1]=0;
	color[n]=1;
	while(!qq.empty()){
		int node=qq.front();
		qq.pop();
		for(auto i:G[node]){
			if(color[i]==-1){
				color[i]=color[node];
				qq.push(i);
			}
		}
	}
	int f=0,s=0;
	for(int i=1;i<=n;i++)
		if(color[i]==0)f++;
		else s++;
	if(f>s)cout<<"Fennec\n";
	else cout<<"Snuke\n";
//	cout<<f<<' '<<s<<endl;
//	for(int i=1;i<=n;i++)cout<<color[i]<<' ';
//	puts("");
	return 0;
}
