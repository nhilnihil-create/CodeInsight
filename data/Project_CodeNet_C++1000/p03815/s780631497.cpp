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
	if (n <= 6) {
		cout << 1;
		return 0;
	}
	if (n <= 11) {
		cout << 2;
		return 0;
	}
	cout << 2 * (n / 11) + ((n % 11 != 0)?((n % 11 > 6)?2:1):0);
} 









