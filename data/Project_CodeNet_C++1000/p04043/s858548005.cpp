#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<vector<int>> Graph;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
#define pi 3.14159265359
#define inf 2147483647
#define INF 9223372036854775807
#define mod 1000000007
#define mod2 998244353

int main() {
	map<int, int> m;
	for(int i = 0; i < 3; i++) {
		int x; cin >> x;
		if(!m.count(x)) m[x] = 1;
		else m[x]++;
	}
	string ans;
	if(m[5] == 2 && m[7] == 1) ans = "YES";
	else ans = "NO";
	cout << ans << endl;
	return 0;
}