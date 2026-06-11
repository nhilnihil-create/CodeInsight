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
	int x, y;
	cin >> x >> y;
	if(x == 2 || y == 2) puts("No");
	else if(x == 4 || x == 6 || x == 9 || x == 11){
		if(y == 4 || y == 6 || y == 9 || y == 11){
			puts("Yes");
		}else puts("No");
	}else{
		if(y == 4 || y == 6 || y == 9 || y == 11){
			puts("No");
		}else puts("Yes");
	}
 	return 0;
}