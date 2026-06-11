#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)
const lli mod = 1e9+7;

lli n, m;

lli modfact(lli x){
	if(x == 0) return 1;
	return (x*modfact(x-1)%mod)%mod;
}

int main(void){
	cin >> n >> m;
	lli ans;
	if(n == m){
		ans = (2*modfact(n)*modfact(m))%mod;
	}else if(n == m-1 || n == m+1){
		ans = (modfact(n)*modfact(m))%mod;
	}else{
		ans = 0;
	}
	cout << ans << endl;
	return 0;
}
