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
ll a[N];
int main(){
	int n;
	ll x,ans=0;
	scanf("%d%lld",&n,&x);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<n;i++){
		if(a[i]+a[i+1]<=x) continue;
		else if(a[i]<=x){
			ll tmp=(a[i]+a[i+1]-x);
			ans+=tmp;
			a[i+1]-=tmp;
		}
		else {
			ll tmp=a[i]+a[i+1]-x;
			a[i+1]=0;
			ans+=tmp;
		}
	}
	printf("%lld\n",ans); 
	return 0;
}