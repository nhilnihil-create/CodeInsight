#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

bool check(ll n, ll m, ll k){
	return 2*k + 2*max(0LL, k - n) <= m;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	ll n, m;
	cin>>n>>m;
	ll lo = 0, hi = 1e13;
	while(lo < hi){
		ll mi = lo + (hi - lo + 1)/2;
		if(check(n, m, mi))lo = mi;
		else hi = mi - 1;
	}
	cout<<lo<<endl;

	return 0;
}