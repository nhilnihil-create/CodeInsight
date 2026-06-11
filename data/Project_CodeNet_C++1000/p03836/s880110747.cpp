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
	int sx, sy, tx, ty; cin >> sx >> sy >> tx >> ty;
	string ans;
	int r = tx - sx, u = ty - sy;
	for(int i = 0; i < u; i++) ans += 'U';
	for(int i = 0; i < r; i++) ans += 'R';
	for(int i = 0; i < u; i++) ans += 'D';
	for(int i = 0; i <= r; i++) ans += 'L';
	for(int i = 0; i <= u; i++) ans += 'U';
	for(int i = 0; i <= r; i++) ans += 'R';
	ans += "DR";
	for(int i = 0; i <= u; i++) ans+= 'D';
	for(int i = 0; i <= r; i++) ans+= 'L';
	ans += 'U';
	cout << ans << endl;
	return 0;
}
