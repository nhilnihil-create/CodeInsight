#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define nn 2000008
int xi[nn],n,T,L,ri[nn];

int add[nn],yi[nn],sum=0;
signed main(){
	scanf("%lld%lld%lld",&n,&L,&T);for(int i=0;i<n;i++) scanf("%lld%lld",&xi[i],&ri[i]),ri[i]=3-ri[i]*2;
	
	for(int i=0;i<n;i++){
		yi[i]=((ri[i]*T+xi[i])%L+L)%L;
		int rot;
		if(ri[i]==1) rot=(T+xi[i])/L;
		else rot=(L-1-xi[i]+T)/L;
		
		sum+=rot*ri[i];
		add[i]-=rot*ri[i]*(n-1)+rot*ri[i];
	}
	sort(yi,yi+n);
	for(int i=0;i<n;i++) printf("%lld\n",yi[((add[i]+sum+i)%n+n)%n]);
	
	return 0;
}