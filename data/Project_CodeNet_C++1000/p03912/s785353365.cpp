#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<(n);i++)

signed main(){
	int n,m;cin>>n>>m;
	vector<int>x(n);
	for(auto&& u:x)cin>>u;
	map<int,int>cnt,cntp,cntm;
	for(auto&& u:x){cnt[u]++;cntm[u%m]++;}
	for(auto&& u:cnt){cntp[u.first%m]+=u.second/2;}

	int ret=0;
	ret+=cntm[0]/2;
	if(m%2==0)ret+=cntm[m/2]/2;
	for(int i=1;i<=(m-1)/2;i++){
		int x=i,y=m-x;
		if(cntm[x]>cntm[y])swap(x,y);
		int nx=cntm[x],ny=cntm[y];
		ret+=nx;
		ret+=min((ny-nx)/2,cntp[y]);
	}
	cout<<ret<<endl;

}
