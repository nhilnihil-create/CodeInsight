#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5,M=1e6+5,inf=0x3f3f3f3f,mod=1e9+7;
#define mst(a) memset(a,0,sizeof a)
#define lx x<<1
#define rx x<<1|1
#define reg register
#define PII pair<int,int>
#define fi first 
#define se second
ll ksm(ll a,ll n){
	ll ans=1;
	while(n){
		if(n&1) ans=ans*a;
		a=a*a;
		n>>=1;
	} 
	return ans;
}
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	printf("%lld\n",1LL*k*ksm(k-1,n-1));
	return 0;
}