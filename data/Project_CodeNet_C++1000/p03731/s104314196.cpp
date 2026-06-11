#include <bits/stdc++.h>
using namespace std;
#define dhoom ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);  
typedef long long ll;
typedef long double ld;
const ll inf = 1e18;
const int nax = 2e6 + 7;
const ll mod = 1e9 + 7;
//ll tree[4 * nax];
//9uS-22RSwk7gQqh
int main()
{
	ll n , t;
	cin >> n >> t;
	ll a[n];
	for(int i = 0 ; i < n ; i++)
		cin >> a[i];
	sort(a , a + n);
	ll ans = 0;
	ll x = 0;
	for(int i = 0 ; i < n ; i++){
		if(a[i] < x)
			ans = ans - (x - a[i]);
		x = a[i] + t;
		ans += t;
	}
	cout << ans << endl;
	return 0;
} 


