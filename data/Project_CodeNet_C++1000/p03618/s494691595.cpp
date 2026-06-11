#include <iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
#include<set>
#include<deque>
#include<iomanip>
#include<tuple>
#include<stack>
using namespace std;
typedef long long ll;

typedef pair<int, int> pii;
typedef tuple<int, int, int> ti3;

const ll MOD_CONST = 1000000007;
//const ll MOD_CONST = 998244353;


const int INF = 1000000000;
//const ll INF = 1000000000000000000;



int main() {
	
	string a;
	cin >> a;
	
	int n = a.length();

	map<char, int> m;
	for (int i = 0; i < n; i++) {
		m[a[i]]++;
	}

	ll ans = 1;
	for (int i = 0; i < n; i++) {
		m[a[i]]--;
		ans += (n - i - 1);
		ans	-= m[a[i]];

	}
	cout << ans << endl;

}

