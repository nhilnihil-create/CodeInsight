#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5,M=2e4+5,inf=0x3f3f3f3f,mod=1e9+7;
#define mst(a,b) memset(a,b,sizeof a)
#define lx x<<1
#define rx x<<1|1
#define reg register
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
#define il inline
int vis[N];
int main(){
	int n;cin>>n;
	int f=1,jg=n&1;
	ll ans=1;
	int cnt=0;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		if(!x) cnt++;
		if(jg&&(x&1)) f=0;
		else if(!jg&&(x%2==0)) f=0;
		else if(jg&&cnt>1) f=0;
		if(!vis[x]){
		if(x) ans=ans*2%mod;
		vis[x]=1;
		} 
	}
	if(!f) cout<<0;
	else cout<<ans; 
	return 0;
}