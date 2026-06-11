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
	int n;
	cin >> n;
	vector<ll> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		if (i) {
			v[i] = v[i] + v[i - 1];
		}
	}
	vector<ll> a = v;
	ll ans = 0;
	ll curr = 0;
	for (int i = 0; i < n; ++i) {
		v[i] = curr + v[i];
		if (i % 2 == 0 && v[i] <= 0) {
			curr += abs(v[i]) + 1;
		    ans += abs(v[i]) + 1;
		}
		if (i % 2 == 1 && v[i] >= 0) {
			curr -= v[i] + 1;
			ans += v[i] + 1;
		}
	}
	v = a;
	ll ans2 = ans;
	ans = 0;
	curr = 0;
	for (int i = 0; i < n; ++i) {
		v[i] = curr + v[i];
		if (i % 2 == 1 && v[i] <= 0) {
			curr += abs(v[i]) + 1;
		    ans += abs(v[i]) + 1;
		}
		if (i % 2 == 0 && v[i] >= 0) {
			curr -= v[i] + 1;
			ans += v[i] + 1;
		}
	}
	cout << min(ans,ans2);
	
}


