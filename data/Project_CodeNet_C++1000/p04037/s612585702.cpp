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
int n , a[N] ;

inline bool get (int x) {
	if (!((a[x] - x) & 1)) return 1 ;
	int low = x , high = n ;
	while (high - low > 1) {
		int mid = (low + high) >> 1 ;
		if (a[mid] == x + 1) low = mid ;
		else high = mid ;
	}
	if (!((low + 1 - x) & 1)) return 1 ;
	return 0 ;
}

int main(){
	ios::sync_with_stdio(false) , cin.tie(0) , cout.tie(0) ;

	cin >> n ;
	for (int i = 0 ; i < n ; i ++) cin >> a[i] ;

	sort(a , a + n , greater<int>()) ;

	for (int i = 0 ; i < n ; i ++) {
		if (i == n - 1 || a[i + 1] <= i + 1) return cout << (get(i) ? "First" : "Second") << '\n' , 0 ;
	}
}
