#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <numeric>
#include <cmath>

using namespace std;

typedef long long int ll;

#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;
const ll MAXN = 1e9;

int main()
{
	ll n;
	cin >> n;
	vector<ll> a(n),t(n);
	for(int i = 0; i < n; i++) cin >> t[i];
	for(int i = 0; i < n; i++) cin >> a[i];

	if(a[0] != t[n-1]){
		cout << 0 << endl;
	}else
	{
		ll ans = 1;
		for(int i = 1; i < n-1; i++){
			if(t[i] == t[i-1] && a[i] == a[i+1]){
				ans *= min(t[i],a[i]);
				ans %= mod;
			}else if(t[i] > t[i-1] && a[i] == a[i+1] && a[i] < t[i]){  //h[i] == t[i]
				ans = 0;
			}else if(t[i] == t[i-1] && a[i] > a[i+1] && a[i] > t[i]){  //h[i] == a[i]
				ans = 0;
			}else if(t[i] > t[i-1] && a[i] > a[i+1] && a[i] != t[i]){   //h[i] == t[i] == a[i]
				ans = 0;
			}
		}
		cout << ans << endl;
	}

	return 0;
}