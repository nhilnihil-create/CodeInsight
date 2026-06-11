#include<bits/stdc++.h>
#define IL inline
#define _ 1000005
#define ll long long
using namespace std ;

int n , f[_] , s[_] , p[_] , Ans ;
#define mod 1000000007

int main() {
	cin >> n ; 
	for(int i = 1; i <= n; i ++) {
		f[i] = ((i >= 3) ? p[i - 3] : 0) + 1 ;
		s[i] = (s[i - 1] + f[i]) % mod ; p[i] = (p[i - 1] + s[i]) % mod ; 
	}
	Ans = 0 ;
	for(int i = 1; i < n; i ++) Ans = (Ans + 1ll * f[i] * (n - 1) % mod * n % mod) % mod ;
	cout << (Ans + 1 + 1ll * f[n] * (n - 1) % mod) % mod  << endl ;
	return 0 ; 
}
