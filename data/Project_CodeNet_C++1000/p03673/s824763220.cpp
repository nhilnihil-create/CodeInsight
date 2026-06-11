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
ll n;
deque<ll>arr;

int main(){
	IOS
	cin >> n;
	for(int i=0;i<n;i++){
		ll x;
		cin >> x;
		if(i&1){
			arr.pf(x);
		}
		else{
			arr.pb(x);
		}
	}
	if(n&1){
		for(int i=arr.size()-1;i>=0;i--){
			cout << arr[i] << ' ';
		}
		cout << '\n';
	}
	else{
		for(auto x:arr){
			cout << x << ' ';
		}
		cout << '\n';
	}
}
