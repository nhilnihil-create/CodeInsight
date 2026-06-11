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
	int w, h, n;
	cin >> w >> h >> n;
	int x1 = 0, x2 = w;
	int y1 = 0, y2 = h;
	rep(i,n){
		int x, y, a;
		cin >> x >> y >> a;
		if(a == 1){
			if(x1 < x) x1 = x;
		}else if(a == 2){
			if(x2 > x) x2 = x;
		}else if(a == 3){
			if(y1 < y) y1 = y;
		}else if(a == 4){
			if(y2 > y) y2 = y;
		}
	}
	int ans;
	if(x1 >= x2 || y1 >= y2) ans = 0;
	else ans = (y2-y1)*(x2-x1);
	cout << ans << endl;
	return 0;
}