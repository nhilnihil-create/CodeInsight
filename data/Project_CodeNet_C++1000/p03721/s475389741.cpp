#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e3+5,M=2e4+5,inf=0x3f3f3f3f,mod=1e9+7;
#define mst(a,b) memset(a,b,sizeof a)
#define lx x<<1
#define rx x<<1|1
#define reg register
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
#define il inline
int n;
ll k;
map<int,ll>mp;
int main(){
	scanf("%d%lld",&n,&k);
	for(int i=1,x,y;i<=n;i++){
		scanf("%d%d",&x,&y);
		mp[x]+=y;
	}
	ll s=0;
	for(auto p:mp){
		if(s+p.se<k) s+=p.se;
		else {
			printf("%d",p.fi);
			break;
		}
	}
	return 0;
}