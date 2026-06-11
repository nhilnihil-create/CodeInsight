//              +-- -- --++-- +-In the name of ALLAH-+ --++-- -- --+              \\

#include <bits/stdc++.h>

#define F first
#define S second
#define _sz(x) (int)x.size()

using namespace std ;
using ll = long long ;
using ld = long double ;
using pii = pair <int , int> ;

int const N = 1e5 + 20 ;
int ss , n , a[N] , o ;

int main(){
	ios::sync_with_stdio(false) , cin.tie(0) , cout.tie(0) ;

	cin >> ss >> n ;

	for (int i = 0 ; i < n ; i ++) cin >> a[i] , o += a[i] & 1 ;

	if (o > 2) return cout << "Impossible\n" , 0;

	bool fl = 0 ;
	for (int i = 0 ; i < n ; i ++) {
		if (!fl && (a[i] & 1)) swap(a[0] , a[i]) , fl = 1 ;
		else if (a[i] & 1) swap(a[n - 1] , a[i]) ;
	}

	for (int i = 0 ; i < n ; i ++) cout << a[i] << ' ' ; cout << '\n' ;

	vector <int> vec ;
	if (a[0] > 1) vec.push_back(a[0] - 1) ; 
	for (int i = 1 ; i < n - 1 ; i ++) vec.push_back(a[i]) ;
	if (n > 1) vec.push_back(a[n - 1] + 1) ;
	else vec.push_back(1) ;

	cout << vec.size() << '\n' ;
	for (int x : vec) cout << x << ' ' ;
	cout << '\n' ;
}
