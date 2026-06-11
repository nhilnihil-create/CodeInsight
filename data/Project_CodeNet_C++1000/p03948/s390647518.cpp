#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
ll n, t, a[100008];

int main(){
	cin >> n >> t;
	for(ll i = 1; i <= n; i++){cin >> a[i];}
	
	ll minp = 1e9+1;
	ll maxd = 0;
	ll ans = 0;
	
	for(ll i = 1; i <= n; i++){
		if(a[i]-minp == maxd){
			ans++;
		}
		if(a[i]-minp > maxd){
			maxd = a[i]-minp;
			ans = 1;
		}
		
		minp = min(a[i], minp);
	}
	
	cout << ans << endl;
	return 0;
}