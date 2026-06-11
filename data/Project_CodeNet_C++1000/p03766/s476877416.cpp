#include <bits/stdc++.h>
const int N=1000005,mu=1000000007;
void reduce(int &x) { x+=x>>31&mu; }
int f[N],n,sum,ans; 
int main(){
	scanf("%d",&n);
	if (n==1){
		puts("1");
		return 0;
	}
	f[0]=1;
	int t=1ll*(n-1)*(n-1)%mu;
	ans=t+1;
	for (int i=1;i<=n;i++){
		reduce(f[i]+=f[i-1]-mu);
		if (i-3>=0) reduce(sum+=f[i-3]-mu);
		reduce(f[i]+=sum-mu);
		if (i<n-1) reduce(ans+=f[i]*1ll*t%mu-mu);
		else if (i==n-1) reduce(ans+=f[i]*1ll*(n-1)%mu-mu);
		else reduce(ans+=f[i]-mu);
		if (i<n-1) reduce(ans+=f[i]*1ll*(i+1)%mu-mu);
	}
	printf("%d\n",ans);
}