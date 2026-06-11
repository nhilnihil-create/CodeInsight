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
	int n, uni=0;
	cin >> n;
	map<int, int> t;
	rep(i,n){
		int a; cin >> a;
		if(a>=1 && a<=399) t[1]++;
		else if(a>=400 && a<=799) t[2]++;
		else if(a>=800 && a<=1199) t[3]++;
		else if(a>=1200 && a<=1599) t[4]++;
		else if(a>=1600 && a<=1999) t[5]++;
		else if(a>=2000 && a<=2399) t[6]++;
		else if(a>=2400 && a<=2799) t[7]++;
		else if(a>=2800 && a<=3199) t[8]++;
		else uni++;
	}
	int ans=0, m, b;
	for(auto x : t){
		if(x.second > 0) ans++;
	}
	if(ans == 0) m = 1;
	else m = ans;
	b = ans+uni;
	cout << m << " " << b << endl;
	return 0;
}