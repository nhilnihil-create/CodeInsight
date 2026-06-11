#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i <= (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define printa(x,m,n) for(ll i = (m); i <= n; i++){cout << (x[i]) << " ";} cout<<endl;

ll q, a, b, c, d, cs[100008], ct[100008];
string s, t;

int main(){
	cin.tie(0); ios::sync_with_stdio(false);
	
	cin >> s >> t >> q;
	cs[0] = 0;
	ct[0] = 0;
	for(ll i = 0; i < s.size(); i++){
		cs[i+1] = (s[i] == 'A')? 1 : 2;
		cs[i+1] += cs[i];
	}
	for(ll i = 0; i < t.size(); i++){
		ct[i+1] = (t[i] == 'A')? 1 : 2;
		ct[i+1] += ct[i];
	}
	
	rep(j, 1, q){
		cin >> a >> b >> c >> d;
		if((cs[b]-cs[a-1])%3 == (ct[d]-ct[c-1])%3){
			print("YES")
		}
		else{
			print("NO")
		}
	}
	
	return 0;
}