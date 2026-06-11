#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const ll mod = 1000000007;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int n, m;
	cin>>n>>m;
	if(abs(n - m) > 1){
		cout<<0<<endl;
		exit(0);
	}
	ll ans = 1;
	for(int i = 1; i <= n; i++){
		(ans *= i) %= mod;
	}
	for(int i = 1; i <= m; i++){
		(ans *= i) %= mod;
	}
	if((n^m)%2 == 0){
		ans <<= 1;
		if(ans >= mod)ans -= mod;
	}
	cout<<ans<<endl;

	return 0;
}