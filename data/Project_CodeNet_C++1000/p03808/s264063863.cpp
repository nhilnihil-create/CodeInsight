#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i <= (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define printa(x,m,n) for(ll i = (m); i <= n; i++){cout << (x[i]) << " ";} cout<<endl;

ll n;

int main(){
	cin.tie(0); ios::sync_with_stdio(false);
	
	cin >> n;
	if(n == 1){
		print("YES")
		return 0;
	}
	
	ll a[n+1];
	ll sum = 0;
	rep(i, 1, n){
		cin >> a[i];
		sum += a[i];
	}
	
	if(sum%(n*(n+1)/2) != 0){
		print("NO")
	}
	else{
		ll da[n+1];
		rep(i, 1, n-1){
			da[i] = a[i+1]-a[i];
		}
		da[n] = a[1]-a[n];
		
		ll m = sum/(n*(n+1)/2);
		ll ans = 0;
		rep(i, 1, n){
			if(da[i] > m){
				print("NO")
				return 0;
			}
			
			if(da[i] < m){
				if((m-da[i])%n == 0){
					ans += (m-da[i])/n;
				}
				else{
					print("NO")
					return 0;
				}
			}
		}
		if(ans == m){
			print("YES")
		}
		else{
			print("NO")
		}
	}
	
	return 0;
}