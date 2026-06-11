#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

using namespace std;

#define fori(x) for (int i = 0; i < x; ++i)
#define forj(x) for (int j = 0; j < x; ++j)

typedef long long ll;

const int INF = 2e9 + 5;
const int alength=100100;

int main() {
	ll n,c,k;
	cin>>n>>c>>k;
	ll t[alength]={};
	fori(n){cin>>t[i];}
	sort(t,t+n);
	ll ans=0;
	for(ll i=0;i<n;){
		++ans;
		ll count=0;
		for(ll j=0;i+j<n&&t[i+j]-t[i]<=k&&j<c;++j,++count);
		i+=count;
	}
	cout<<ans;
}