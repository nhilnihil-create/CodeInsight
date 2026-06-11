#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <cstdint>
#include <vector>

using namespace std;
typedef long long ll;


ll ans,mx,mn=1e8,sum,cnt;
ll odd,even;
int main(){
	ll n;
	cin>>n;
	for(ll i=0; i<n; i++){
		ll a;
		cin>>a;
		if(a%2!=0) odd++;
		else even++;
	}
	if(odd%2==0) cout<<"YES";
	else cout<<"NO";
}
