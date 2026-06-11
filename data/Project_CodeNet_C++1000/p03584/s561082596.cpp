#include<bits/stdc++.h>
typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,a) FOR(i,0,a)
	
using namespace std;
const int MAX_N=1e5;
int N;
ll K,A[MAX_N],B[MAX_N];
int main(){
	scanf("%d %lld",&N,&K);
	REP(i,N){
		scanf("%lld %lld",A+i,B+i);
	}
	K++;
	int dig=0;
	{
		ll k=K;
		while(k){
			dig++;
			k>>=1;
		}
	}
	ll ans=0;
	REP(i,dig){
		if((K>>i)&1){
			ll k=(1ll<<i)-1+((K>>(i+1))<<(i+1));
			ll sm=0;
			REP(j,N){
				if((k|A[j])==k){
					sm+=B[j];
				}
			}
			ans=max(ans,sm);
		}
	}
	printf("%lld\n",ans);
}