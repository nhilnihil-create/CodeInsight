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

ll n, a[100008], mx, mn, c;
string s;

int main(){
	cin.tie(0); ios::sync_with_stdio(false);
	
	cin >> n;
	
	c = 0;
	rep(i, 1, n){
		cin >> a[i];
		mx = (i == 1)? a[i] : max(a[i], mx);
		mn = (i == 1)? a[i] : min(a[i], mn);
	}
	if(mx-mn > 1){
		print("No")
		return 0;
	}
	if(mx == mn){
		if((1 <= mx && mx <= n/2) || mn == n-1){
			print("Yes")
		}
		else{
			print("No")
		}
	}
	else{
		rep(i, 1, n){
			if(a[i] == mx){c++;}
		}
		if(c == 1){
			print("No")
			return 0;
		}
		if(n-c+1 <= mx && mx <= n-c+c/2){
			print("Yes")
		}
		else{
			print("No")
		}
	}
	
	return 0;
}