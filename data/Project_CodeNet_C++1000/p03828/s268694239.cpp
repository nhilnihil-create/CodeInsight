#include <iostream>
#include <iterator>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <numeric>
#include <iomanip>
#include <limits>
#include <set>
#include <map>

typedef long long ll;

using namespace std;

void factoring(ll n, map<ll, ll>& mp) {
	for (ll i = 2; i * i <= n; i++) {
		while (n % i == 0) {
			mp[i]++;
			n /= i;
		}
	}
	if (n != 1) mp[n]++;
}

int main(){

    ll n;
    cin>>n;
    map<ll,ll> mp;

    const ll MOD = 1000000007;

    ll ans=1;

    for(ll i=1;i<=n;i++){
        factoring(i, mp);
    }

    for(auto i:mp){
        ans*=(i.second+1);
        ans%=MOD;
	}
    
    cout<<ans<<endl;

    return 0;
}
