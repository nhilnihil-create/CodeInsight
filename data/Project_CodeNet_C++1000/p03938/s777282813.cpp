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

ll n, p[20008], a[20008], b[20008], aa[20008], bb[20008];
string s;

int main(){
	cin.tie(0); ios::sync_with_stdio(false);
	
	cin >> n;
	rep(i, 1, n){
		cin >> p[i];
		a[i] = i;
		b[i] = n-i+1;
	}
	
	memset(aa, 0, sizeof(aa));
	memset(bb, 0, sizeof(bb));
	rep(i, 1, n){
		aa[p[i]+1] = n-i;
		bb[p[i]-1] = n-i;
	}
	
	rep(i, 2, n){aa[i] += aa[i-1];}
	rrep(i, n-1, 1){bb[i] += bb[i+1];}
	rep(i, 1, n){cout << a[i]+aa[i] << " ";}
	cout << endl;
	rep(i, 1, n){cout << b[i]+bb[i] << " ";}
	cout << endl;
	return 0;
}