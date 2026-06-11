#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <complex>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <cassert>
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
const ll MOD=1e9+7;
int main()
{
	ll n; cin>>n;
	ll ans=1;
	ll x[100001];
	for(int i=0; i<n; i++) cin>>x[i];
	ll i=0;
	for(ll r=0; r<n; r++){
		while(1){
			if(x[i]<2*i-2*r+1) break;
			if(i==n-1) break;
			i++;
		}
		ans*=(i+1-r);
		ans%=MOD;
	}
	cout<<ans<<endl;
	return 0;
}