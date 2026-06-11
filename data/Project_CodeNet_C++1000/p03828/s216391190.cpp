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
unordered_map<int,int>mp;
int main(){
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		int x=i; 
		for(int j=2;j*j<=x;j++){
			if(x%j==0){
				while(x%j==0) mp[j]++,x/=j;
			}
		}
		if(x!=1) mp[x]++;
	}
	ll ans=1;
	for(auto p:mp){
		ans=ans*(p.se+1)%mod;
	}
	printf("%lld\n",ans%mod);
	return 0;
}