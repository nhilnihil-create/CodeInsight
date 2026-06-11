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

ll n, buf, a[108], mx, mn;
string s;

int main(){
	cin.tie(0); ios::sync_with_stdio(false);
	
	cin >> n;
	memset(a, 0, sizeof(a));
	mx = 1;
	mn = n-1;
	rep(i, 1, n){
		cin >> buf;
		a[buf]++;
		mx = max(buf, mx);
		mn = min(buf, mn);
	}
	bool ans = true;
	if(mx > n-1 || mn < (mx+1)/2){
		ans = false;
	}
	else{
		rep(i, mn+1, mx){
				if(a[i] < 2){
					ans = false;
				}
		}
		if(a[mn] != mx%2+1){
			ans = false;
		}
	}
	
	if(ans){
		print("Possible")
	}
	else{
		print("Impossible")
	}
	return 0;
}