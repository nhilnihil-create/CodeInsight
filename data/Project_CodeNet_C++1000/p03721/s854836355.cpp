#include <iostream>
#include <algorithm> 
#include <cmath>
//#include <bitset>
//#include <deque>
#include <iterator>
#include <map> 
//#include <queue>
//#include <stack>
#include <string>
#include <vector>
#include <array>
//#include <tuple>
//#include <unordered_map>
//#include <unordered_set>

using namespace std;

typedef long long ll;
struct __{__(){ios_base::Init i;ios_base::sync_with_stdio(0);cin.tie(0);}}__; 



int main() {
	ll n, k;
	cin >> n >> k;
	//vector<pair<int,int>> v(n);
	map<ll,ll> m;
	for (int i = 0; i < n; ++i) {
		ll x, y;
		cin >> x >> y;
		m[x] += 1LL * y;
		//cin >> v[i].first >> v[i].second; 
	}
	//sort(v.begin(),v.end());
	ll val = 0;
	for (auto it = m.begin(); it != m.end(); ++it) {
		k -= it->second;
		if (k <= 0) {
			val = it->first;
			break;
		}
	}
	cout << val;
}





