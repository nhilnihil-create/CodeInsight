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

	int n, x;
	cin>>n;
	map<int, int> mp;
	for(int i = 0; i < n; i++){
		cin>>x; mp[x]++;
	}
	if(n%2 == 0){
		ll ans = 1;
		for(int i = 1; i <= n; i += 2){
			if(mp[i] != 2){
				cout<<0<<endl;
				exit(0);
			}
			ans <<= 1;
			if(ans >= mod)ans -= mod;
		}
		cout<<ans<<endl;
	}else{
		ll ans = 1;
		if(mp[0] != 1){
			cout<<0<<endl;
			exit(0);
		}
		for(int i = 2; i <= n; i += 2){
			if(mp[i] != 2){
				cout<<0<<endl;
				exit(0);
			}
			ans <<= 1;
			if(ans >= mod)ans -= mod;
		}
		cout<<ans<<endl;
	}

	return 0;
}