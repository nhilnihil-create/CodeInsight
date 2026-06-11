#include <cmath>
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<set>
#include<map>
#include<bitset>
#include<iomanip>
#include<stack>
#include<set>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll mod = 1000000007;
int main() {
	ll x;
	cin >> x;
	if (x < 7) {
		cout << "1" << endl;
	}
	else {
		ll y;
		y = x;
		ll ans = (y / 11)*2;
		ll k = y % 11;
		if (k > 6) {
			cout << ans + 2 << endl;
		}
		else if(k!=0){
			cout << ans + 1 << endl;
		}
		else {
			cout << ans << endl;
		}
	}
	return 0;
}