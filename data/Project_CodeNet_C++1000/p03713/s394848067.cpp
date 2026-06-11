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
ll solve(ll h , ll w){
	if(h % 3 == 0)
		return 0;
	ll ans = w;
	for(int i = 1 ; i <= h - 1 ; i++){
		ll  temp[]= { i * (w/2) , i * (w - w/2) , (h - i)*w};
		sort(temp , temp + 3);
		ans = min(ans , temp[2] - temp[0]);
	}
	return ans;
}
int main()
{
	ll h , w;
	cin >>  h >> w;
	cout << min(solve(h , w) , solve(w , h)) << endl;
	return 0;
} 


