#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define IOS ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
#define ff first
#define ss second
#define pf push_front
#define pb push_back
#define debug(val) cerr << "The Value Of " << #val << " is : " << val << '\n';
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
const ll mod = 1e9 + 7;
const ll inf = 0x3f3f3f3f;
const ll mininf = -922337203685477;
const ll nax = 0;
ll n, m;

ll faktorial(ll n){
		ll x=n;
		ll ans=1;
		while(x){
			ans=(ans*x)%mod;
			x--;
		}
		return ans;
	}
	
int main(){
	IOS
	cin >> n >> m;
	if(abs(n-m)>=2){
		cout << 0 << '\n';
	}
	else if(n==m){
		cout << (2*faktorial(n)*faktorial(m))%mod << '\n';
	}
	else{
		cout << (faktorial(n)*faktorial(m))%mod << '\n';
	}
}
