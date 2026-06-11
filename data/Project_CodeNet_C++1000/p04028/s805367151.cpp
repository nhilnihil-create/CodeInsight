#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    int n, m, d[5003][5003] = {1};
    string s;
    cin >> n >> s; m = (int)s.length();
    for (int i = 1; i <= n; i++) for (int j = 0; j <= n; j++) d[i][j] = ((d[i - 1][max(0, j - 1)] + d[i - 1][j + 1]) % mod + d[i - 1][j + 1]) % mod;
    cout << d[n][m];
}
