#include <iostream>
#include <algorithm>
using namespace std ;
using ll = long long ;

int main(){
	ll h,w ;
	cin >> h >> w ;
	ll ans = 100000000000 ;
	for(int i=1;i<h;i++){
		ll a = i*w ;
		ll b = ((h-i)*w%2==0?(h-i)*w/2:((h-i)*w+min(h-i,w))/2) ;
		ll c = h*w-a-b ;
		ans = min(ans,max(a,b)-min(a,c)) ;
	}
	for(int i=1;i<w;i++){
		ll a = i*h ;
		ll b = ((w-i)*h%2==0?(w-i)*h/2:((w-i)*h+min(w-i,h))/2) ;
		ll c = h*w-a-b ;
		ans = min(ans,max(a,b)-min(a,c)) ;
	}
	cout << ans << endl ;
}
