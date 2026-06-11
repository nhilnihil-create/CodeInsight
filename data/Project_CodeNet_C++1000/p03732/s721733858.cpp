#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=105,M=2e4+5,inf=0x3f3f3f3f,mod=1e9+7;
#define mst(a,b) memset(a,b,sizeof a)
#define lx x<<1
#define rx x<<1|1
#define reg register
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
#define il inline
map<int,int>mp[N];
int main(){
	int n,m,w,v;
	cin>>n>>m;
	mp[0][0]=0;
	for(int i=0;i<n;i++){
		scanf("%d%d",&w,&v);
		for(auto p:mp[i]){
			mp[i+1][p.fi]=max(mp[i+1][p.fi],mp[i][p.fi]);
			if(p.fi+w<=m){
				mp[i+1][p.fi+w]=max(mp[i+1][p.fi+w],mp[i][p.fi]+v);
			}
		}
	}
	int ans=0;
	for(auto p:mp[n]){
		ans=max(ans,p.se);
	}
	cout<<ans<<endl;
	return 0;
}