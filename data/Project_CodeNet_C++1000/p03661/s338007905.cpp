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
//		freopen("input.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	vector<ll> a(n);
	ll ans = 1e18,x = 0,y=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		x += a[i];
	}
	for(int i=0;i<n-1;i++){
		y+=a[i];
		x-=a[i];
		ans = min(ans,abs(x-y));
	}
	cout << ans << endl;
}