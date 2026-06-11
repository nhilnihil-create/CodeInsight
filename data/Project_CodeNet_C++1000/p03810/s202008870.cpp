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
int n , a[N] , cnt[2] , mn ;
ll sum ;

inline void print (bool f) {
	cout << (!f ? "First" : "Second") << '\n' ;
	exit(0) ;
}

inline void fill () {
	cnt[0] = cnt[1] = 0 ;
	sum = 0 , mn = a[0] ;
	for (int i = 0 ; i < n ; i ++) cnt[a[i] & 1] ++ , sum += a[i] , mn = min(mn , a[i]) ;
}

void go (int cur = 0) {
	fill() ;
	
	if (!cnt[0]) print(1 ^ cur) ;
	if (cnt[0] == 1) print(0 ^ cur) ;
	if (cnt[1] > 1 || ((sum - n) & 1) || mn == 1) print(!((sum - n) & 1) ^ cur) ;

	int g = 0 ;
	for (int i = 0 ; i < n ; i ++) {
		if (a[i] & 1) a[i] -- ;
		g = __gcd(g , a[i]) ;
	}

	for (int i = 0 ; i < n ; i ++) a[i] /= g ;

	go(cur ^ 1) ;
}

int main(){
	ios::sync_with_stdio(false) , cin.tie(0) , cout.tie(0) ;

	cin >> n ;
	for (int i = 0 ; i < n ; i ++) {
		cin >> a[i] ;
	}

	if (n == 1) print(1) ;

	go() ;
}
