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
	string a, b, c; cin >> a >> b >> c;
    string s(a, 0, 1), t(b, 0, 1), u(c, 0, 1);
    string ans = s + t + u;
    transform(ans.begin(), ans.end(), ans.begin(), ::toupper);
    cout << ans << endl;
	return 0;
}