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
	vector<string> s(10000);
	cin >> s[int('a')] >> s[int('b')] >> s[int('c')];
	int dex = int('a');
	while(1){
		if(s[dex] == ""){
			cout << char((dex)-('a'-'A')) << endl;
			break;
		}
		int dex1 = dex;
		dex = int(s[dex][0]);
		s[dex1].erase(0, 1);
	}
 	return 0;
}