#include<bits/stdc++.h>
using namespace std;

const int N=100100;
int n,m,sm[N];
vector<pair<int,int> >vec[N];
void add(int x,int y){for(;x<=m;x+=x&-x)sm[x]+=y;}
int qry(int x){int ans=0;for(;x;x-=x&-x)ans+=sm[x];return ans;}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		int x,y;cin>>x>>y;
		vec[y-x+1].emplace_back(x,y);
	}
	for(int i=1;i<=m;++i){
		for(auto j:vec[i]){--n;add(j.first,1);add(j.second+1,-1);}
		int res=n;
		for(int j=i;j<=m;j+=i)res+=qry(j);
		cout<<res<<'\n';
	}
	return 0;
}
