#include<bits/stdc++.h>
using namespace std;
long long moder = 1000000007;
long long fac[100005];
int main(){
	long long n,m;
	cin>>n>>m;
	if(n<m) swap(n,m);
	if(n-m>=2){
		cout<<0;
		return 0;
	}
	fac[0] = 1;
	for(int i=1; i<=n+1; i++){
		fac[i]=fac[i-1]*i;
		fac[i]%=moder;
	}
	long long ret = fac[n]*fac[m];
	if(n==m){
		ret%=moder;
		ret*=2;
		cout<<ret%moder;
	}
	else{
		cout<<ret%moder;
	}
}