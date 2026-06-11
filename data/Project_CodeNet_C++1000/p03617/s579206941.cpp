#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD =1e9+7;
using ll=long long;
using Graph = vector<vector<int>>;

int main() {
    ll q, h, s, d, n;
    cin >> q >> h >> s >> d >> n;
    s = min({s, q*4, h*2});
    d = min(2*s, d);
    cout << n/2 * d + n%2*s << endl;
}