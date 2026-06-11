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
#include <unordered_map>
//#include <unordered_set>

using namespace std;

typedef long long ll;
struct __{__(){ios_base::Init i;ios_base::sync_with_stdio(0);cin.tie(0);}}__; 



int main() {
	ll n;
	cin >> n;
	int ans = 1e9 + 7;
	for (ll i = 1; i * i <= n; ++i) {
		if (n % i == 0) {
			int p1 = 0;
			int p2 = 0;
			int a = i, b = n / i;
			while (a) {
				p1++;
				a /= 10;
			}
			while (b) {
				p2++;
				b /= 10;
			}
			ans = min(ans,max(p1,p2));
		}
	}
	cout << ans;
} 














