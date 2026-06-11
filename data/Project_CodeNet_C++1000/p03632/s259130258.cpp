#include<bits/stdc++.h>
// Begin Header {{{
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using Graph = vector<vector<ll>>;
#define rep(i,n) for(ll i=0; i<n; i++)
#define loop(i, j, n) for(ll i=j; i<n; i++)
#define all(x) (x).begin(), (x).end()
constexpr int INF  = 0x3f3f3f3f;
const long long mod=1e9+7;
const long double PI = acos(-1);
// }}} End Header

int main() {
	int a, b, c, d, ans=0;
	cin >> a >> b >> c >> d;
	rep(i,101){
		if((i>a && i<=b) && (i>c && i<=d)){
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}