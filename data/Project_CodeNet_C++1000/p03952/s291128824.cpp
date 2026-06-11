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

ll n, x;
string s;

int main(){
	cin.tie(0); ios::sync_with_stdio(false);
	
	cin >> n >> x;
	
	if(x == 1 || x == 2*n-1){print("No")}
	else{
		print("Yes")
		if(x == 2){
			rep(i, 4, n+1){print(i)}
			print(1)
			print(2)
			print(3)
			rep(i, n+2, 2*n-1){print(i)}
		}
		else{
			if(x == 2*n-2){
				rep(i, 1, n-2){print(i)}
				print(2*n-3)
				print(2*n-2)
				print(2*n-1)
				rep(i, n-1, 2*n-4){print(i)}
			}
			else{
				if(x-1 > n-2){
					rep(i, 1, n-2){print(i)}
					print(2*n-1)
					print(x)
					print(x-1)
					print(2*n-2)
					rep(i, n-1, x-2){print(i)}
					rep(i, x+1, 2*n-3){print(i)}
				}
				else{
					rep(i, 1, x-2){print(i)}
					rep(i, x+1, n){print(i)}
					print(2*n-1)
					print(x)
					print(x-1)
					print(2*n-2)
					rep(i, n+1, 2*n-3){print(i)}
				}
			}
		}
	}
	
	return 0;
}