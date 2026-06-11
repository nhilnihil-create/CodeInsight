#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1000005,M=1e9+7;
int n,f[N],sum;
signed main(){
	scanf("%lld",&n);
	f[n]=sum=n;f[n+1]=1;
	for (int i=n-1;i;i--){
		(f[i]+=(n-1)*(n-1))%=M;
		(f[i]+=sum+i+1-f[i+2]+M)%=M;
		(sum+=f[i])%=M;
	}
	printf("%lld\n",f[1]);
}