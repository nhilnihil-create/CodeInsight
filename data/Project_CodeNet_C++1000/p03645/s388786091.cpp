#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define IOS ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
#define ff first
#define ss second
#define pb push_back
#define debug(val) cerr << "The Value Of " << #val << " is : " << val << '\n';
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
const ll mod = 1e9 + 7;
const ll inf = 0x3f3f3f3f;
const ll mininf = -922337203685477;
const ll nax = 2e5+5;
ll n, m;
vector<ll>arr[nax];
	
int main(){
	IOS
	cin >> n >> m;
	while(m--){
		ll a, b;
		cin >> a >> b;
		arr[a].pb(b);
		arr[b].pb(a);
	}
	bool cek=0;
	for(auto x:arr[1]){
		for(auto y:arr[x]){
			if(y==n){
				cek=1;
				break;
			}
		}
	}
	if(cek) cout << "POSSIBLE" << '\n';
	else cout << "IMPOSSIBLE" << '\n';
}
