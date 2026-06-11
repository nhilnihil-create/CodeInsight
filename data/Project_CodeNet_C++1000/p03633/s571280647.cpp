#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

ll gcd(ll a, ll b) {
   if (a%b == 0) return(b);
   else return(gcd(b, a%b));
}

ll lcm(ll a, ll b){
   return a/gcd(a, b)*b;
}

int main(){
	int N;
	cin >> N;	
	ll ans = 1;
	rep(i,N) {
		ll T;
		cin >> T;
		ans = lcm(ans, T);
	}
	cout << ans << endl;
	return 0;
}
