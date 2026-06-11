#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <cstdint>
#include <map>
 
using namespace std;
typedef long long ll;


ll ans,mx,sum,mn=1e8;
int main(){
	ll n,m;
	cin>>n>>m;
	ll a[n];
	for(ll i=0; i<n; i++){
		cin>>a[i];
	}
	for(ll i=0; i<n; i++){
		if(i>0){
			if(a[i]-a[i-1] < m){
				ans += a[i]-a[i-1];
			}
			else ans += m;
		}
	}
	cout<<ans+m;
}
