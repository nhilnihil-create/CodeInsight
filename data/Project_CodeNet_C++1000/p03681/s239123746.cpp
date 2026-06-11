#include <bits/stdc++.h>


using namespace std;

long long mod = (long long)1e9 + 7;

int main(){
	long long n,m;
	cin>>n>>m;
	if (abs(n-m)>1){
		cout<<0<<endl;
		return 0;
	}
	long long ans = 1;
	for(int i =1; i <=n; i++){
		ans *= i;
		ans %= mod;
	}
	for(int i =1; i <=m; i++){
		ans *= i;
		ans %= mod;
	}
	if (n==m) ans *=2;
	ans %= mod;
	cout<<ans<<endl;
	return 0;
}