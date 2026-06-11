#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>    
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll n, t[100008], a[100008], fix[100008];
ll MOD = 1e9+7;
string str;

int main(){
	cin >> n;
	for(ll i = 1; i <= n; i++){cin >> t[i];}
	for(ll i = 1; i <= n; i++){cin >> a[i];}
	
	ll buf = 0;
	ll ans = 1;
	memset(fix, 0, sizeof(fix));
	for(ll i = 1; i <= n; i++){
		if(t[i] > buf){
			if(t[i] <= a[i]){
				fix[i] = t[i];
				buf = t[i];
			}
			else{
				ans = 0;
			}
		}
	}
	
	buf = 0;
	for(ll i = n; i >= 1; i--){
		if(a[i] > buf){
			if(a[i] <= t[i] && (fix[i] == 0 || fix[i] == a[i])){
				fix[i] = a[i];
				buf = a[i];
			}
			else{
				ans = 0;
			}
		}
	}
	
	for(ll i = 1; i <= n; i++){
		if(fix[i] == 0){
			ans *= min(t[i], a[i]);
			ans %= MOD;
		}
	}
	
	cout << ans << endl;
	return 0;
}