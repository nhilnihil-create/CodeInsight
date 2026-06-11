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
	string s;
	cin >> s;
	vector<char> t(26);
	rep(i,26){
		t[i]='a'+i;
	}
	rep(i,s.size()){
		t.erase(remove(all(t), s[i]), t.end());
	}
	if(t.size()==0) puts("None");
	else cout << t[0] << endl;
	return 0;
}