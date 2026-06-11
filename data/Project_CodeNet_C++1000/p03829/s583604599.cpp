#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <cstdint>
#include <sstream>
#include <map>
#include <vector>
#include <queue>
#include <iomanip>

using namespace std;
typedef long long ll;

ll ans, mx, sum, mn = 1e8, cnt;


int main(){
	ll n,a,b;
	cin>>n>>a>>b;
	ll arr[n];
	for(ll i=0; i<n; i++){
		cin>>arr[i];
	}
	for(ll i=1; i<n; i++){
		ll flag=arr[i]-arr[i-1];
		ll g=flag*a;
		ans +=min(g,b);
	}
	cout<<ans<<endl;
}
