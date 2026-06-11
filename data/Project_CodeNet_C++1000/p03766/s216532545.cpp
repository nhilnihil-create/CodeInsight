#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll p=1e9+7;
ll n,i,sum,f[1000010];
int main(){
	scanf("%lld",&n);
	f[n]=n;f[n-1]=n*n%p;
	for(i=n-2;i>=1;i--){
		sum=(sum+f[i+3])%p;
		f[i]=(f[i+1]+(n-1)*(n-1)%p+sum+i+1)%p;
	}
	printf("%lld",f[1]);
}