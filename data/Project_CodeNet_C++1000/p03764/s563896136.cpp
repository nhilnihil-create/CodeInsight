#include <iostream>
#include <cctype>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <string>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
typedef long long ll;
const int INF = 100000000, mod = 1000000007;
using namespace std;

int main() {
    ll n, m;
    cin >> n >> m;
    ll x[n], y[m], xsum = 0, ysum = 0;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        xsum += (i*x[i] - (n - 1 - i)*x[i]) % mod;
        xsum %= mod;
    }
    for (int i = 0; i < m; i++) {
        cin >> y[i];
        ysum += (i*y[i] - (m - 1 - i)*y[i]) % mod;
        ysum %= mod;
    }
    cout <<(xsum*ysum) % mod << endl;
    return 0;
}