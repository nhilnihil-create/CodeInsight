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
const ll nax = 2e5+5;
ll n, t, arr[nax];

int main(void){
	IOS
	cin >> n >> t;
	for(ll i=0;i<n;i++){
		cin >> arr[i];
	}
	ll tmp=0;
	for(ll i=0;i<n;i++){
		if(i==n-1) tmp+=t;
		else tmp+=(min(arr[i+1], arr[i]+t)-arr[i]);
		//cout << i << ' ' << tmp << '\n';
	}
	cout << tmp << '\n';
}
