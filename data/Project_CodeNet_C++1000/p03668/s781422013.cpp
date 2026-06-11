#include<bits/stdc++.h>
using namespace std;

const int N=100100;
int n;
vector<int>g[N];
int dfs(int x,int fa=-1){
	int ret=0;
	for(int i:g[x])if(i!=fa)ret^=dfs(i,x)+1;
	return ret;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<n;++i){
		int x,y;cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	cout<<(dfs(1)?"Alice\n":"Bob\n");
	return 0;
}
