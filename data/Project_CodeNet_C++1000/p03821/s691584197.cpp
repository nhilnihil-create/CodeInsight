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
	ll n;
	cin>>n;
	ll a[n],b[n];
	for(ll i=0; i<n; i++){
		cin>>a[i]>>b[i];
	}
	for(ll i=n-1; i>=0; i--){
		a[i] +=ans;
		if(a[i]%b[i]!=0){
			ll flag=(((a[i]/b[i])+1)*b[i])-a[i];
			ans +=flag;
		}
		
	}
	cout<<ans<<endl;
}
