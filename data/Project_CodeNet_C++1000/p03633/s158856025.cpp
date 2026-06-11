#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

lli n;

lli gcd(lli a, lli b){
	if(b == 0) return a;
	return gcd(b, a%b);
}

lli lcm(lli a, lli b){
	lli g = gcd(a, b);
	return a/g*b;
}

int main(void){
	cin >> n;
	vector<lli> t(n);
	lli ans = 1;
	rep(i, n){
		cin >> t[i];
		ans = lcm(ans, t[i]);
	}
	cout << ans << endl;

	return 0;
}
