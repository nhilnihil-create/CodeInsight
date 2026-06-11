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
	ll sum = 0;
	//vector<int> p;
	ll minn = 1e9 + 7;
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		if (v[i] % 10 != 0) 
			minn = min(minn,v[i]);
		sum += v[i];
	}
	if (minn == 1e9 + 7) {
		cout << 0;
	}else {
		if (sum % 10 != 0) {
			cout << sum;
		}else {
			cout << sum - minn;
		}
	}
}


