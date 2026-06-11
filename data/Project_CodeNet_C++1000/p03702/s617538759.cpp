#include <bits/stdc++.h>

using namespace std;

#define debug(x) '[' << #x << " is: " << x << "] "
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(10);
	cout << fixed;
	#ifndef ONLINE_JUDGE
	//	freopen("input.txt","r",stdin);
	#endif
	int n,a,b;
	cin>>n>>a>>b;
	vector<ll> h(n);
	for(int i=0;i<n;i++)cin>>h[i];
	ll md,lo=0,hi=1e9;
	while(lo < hi){
		md = (lo + hi)/2;

		ll cur=0;
		for(int i=0;i<n;i++){
			if(md * b >= h[i])continue;
			ll dif = a-b;
			ll sum = h[i] - md * b;
			ll x = (sum + dif - 1)/dif;
			cur += x;
		}
		// if(md == 2)cout << cur << endl;
		// cout << cur << ' ' << md << endl;
		if(cur <= md){
			hi = md;
		}else{
			lo = md+1;
		}

	}
	cout << hi << endl;
}