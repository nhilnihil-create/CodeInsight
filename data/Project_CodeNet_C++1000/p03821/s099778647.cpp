#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MK make_pair
#define REP(i, a, b) for (int i=a; i < b; i++)


bool sort_by(pi c, pi d){
	return c.S < d.S;
}

int main() {
	ll n;
	cin >> n;
	pair<ll,ll> arr[n];
	ll t1, t2;
	REP(i, 0, n){
		cin >> t1 >> t2;
		arr[i] = MK(t1, t2);
	}
	ll ans =0;
	for(int i = n-1; i >= 0; i--){
		ll a = arr[i].F;
		ll b = arr[i].S;
		a += ans;
		ans += (b - (a%b != 0? a%b:b));
	}
	cout << ans;

}
