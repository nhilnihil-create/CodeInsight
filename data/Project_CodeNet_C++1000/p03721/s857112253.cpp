#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define IOS ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
#define ff first
#define ss second
#define pf push_front
#define pb push_back
#define eb emplace_back
#define debug(val) cerr << "The Value Of " << #val << " is : " << val << '\n';
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
const ll mod = 1e9 + 7;
const ll inf = 0x3f3f3f3f;
const ll mininf = -922337203685477;
const ll nax = 1e5+5;
ll n, k;
unordered_map<ll, ll>cnt;	
	
int main(void){
	IOS
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		ll a, b;
		cin >> a >> b;
		cnt[a]+=b;
	}
	for(int i=1;i<=nax;i++){
		if(cnt[i]>=k){
			cout << i << '\n';
			return 0;
		}
		k-=cnt[i];
	}
}
