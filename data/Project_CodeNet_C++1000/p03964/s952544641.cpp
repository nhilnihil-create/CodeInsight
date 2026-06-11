#include<iostream>
#include<algorithm>
using namespace std ;

int main(){
	using ll = long long ;
	ll n ; cin >> n ;
	ll a,b ;
	a = b = 1 ;
	for(int i=0;i<n;i++){
		ll T,A ;
		cin >> T >> A ;
		ll sub = max((a+T-1)/T,(b+A-1)/A) ;
		a = T*sub ;
		b = A*sub ;
	}
	cout << a+b << endl ;
}