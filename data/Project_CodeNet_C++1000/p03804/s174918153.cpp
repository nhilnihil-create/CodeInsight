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
	int n, m;
	cin >> n >> m;
	vector<string> a(n);
	rep(i,n) cin >> a[i];
	vector<string> b(m);
	rep(i,n) cin >> b[i];
	bool ok=true;
	for(int j=0; j+m<n+1; j++){//heigh
		for(int i=0; i+m<n+1; i++){//wide
			rep(k,m){
				if(a[j+k].substr(i,m) == b[k]) ;
				else{
					ok = false;
					break;
				}
			}
			if(ok){
				cout << "Yes" << endl;
				return 0;
			}
			ok = true;
		}
	}
	cout << "No" << endl;
	return 0;
}