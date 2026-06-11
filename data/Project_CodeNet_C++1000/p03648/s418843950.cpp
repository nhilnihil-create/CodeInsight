#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
	ll K;
	cin >> K;
	ll q=K/50, r=K%50;
	vector<ll> ans(50, 49+q);
	for(ll i=0; i<50; ++i){
	    if(i<r) ans[i] += 51-r;
	    else ans[i] -= r;
	}
	cout << 50 << endl;
	cout << ans[0];
	for(int i=1; i<50; ++i) cout << ' ' << ans[i];
	return 0;
}
