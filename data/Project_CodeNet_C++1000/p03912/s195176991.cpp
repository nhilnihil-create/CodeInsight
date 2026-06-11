#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<(n);i++)

signed main(){
	int n,m;cin>>n>>m;
	vector<int>x(n);
	for(auto&& u:x)cin>>u;
	map<int,vector<int>> div;
	for(auto&& u:x)div[u%m].push_back(u);
	int ret=0;
	ret+=div[0].size()/2;
	if(m%2==0)ret+=div[m/2].size()/2;
	for(int i=1;i<=(m-1)/2;i++){
		int x=i,y=m-x;
		int nx=div[x].size(),ny=div[y].size();
		if(nx>ny){swap(x,y);swap(nx,ny);}
		ret+=nx;
		int pr=0;
		map<int,int>cnt;
		for(auto&& u:div[y])cnt[u]++;
		for(auto&& u:cnt)pr+=u.second/2;
		ret+=min((ny-nx)/2,pr);
	}
	cout<<ret<<endl;

}
