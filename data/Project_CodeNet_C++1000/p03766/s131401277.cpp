#include<bits/stdc++.h>
#define mod 1000000007
int f[1000010];
int main(){
	int n;std::cin>>n;
	f[n]=n;f[n-1]=1ll*n*n%mod;
	int sum=0;
	for(int i=n-2;i>0;--i){
		sum=(sum+f[i+3])%mod;
		f[i]=(f[i+1]+1ll*(n-1)*(n-1)%mod+sum+i+1)%mod;
	}
	printf("%d\n",f[1]);
	return 0;
}
