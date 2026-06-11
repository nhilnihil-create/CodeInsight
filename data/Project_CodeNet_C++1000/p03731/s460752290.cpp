#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int n; ll t, x;
	cin>>n>>t;
	ll ans = 0, cur = 0;
	for(int i = 0; i < n; i++){
		cin>>x;
		if(x <= cur){
			ans += x + t - cur;
		}else{
			ans += t;
		}
		cur = x + t;
	}
	cout<<ans<<endl;

	return 0;
}