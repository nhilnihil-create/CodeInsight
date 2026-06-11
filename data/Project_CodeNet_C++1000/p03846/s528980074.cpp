#include<bits/stdc++.h>

#define MOD 1000000007

using ll = long long;
using namespace std;

int n, a[100000];
map<ll, ll> m;

ll modpow(ll a, ll b){
	ll res = 1;
	for(ll i = 0; i < b; ++i){
		res *= a;
		res %= MOD;
	}
	return res;
}


int main(){
	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		m[a[i]]++;
	}
	
	for(int i = n%2+1; i < n; i += 2){
		if(m[i] != 2){
			cout << 0 << endl;
			return 0;
		}
	}

	if(m[0] != n%2){
		cout << 0 << endl;
		return 0;
	}
	
	printf("%lld\n", modpow(2,n/2));
}