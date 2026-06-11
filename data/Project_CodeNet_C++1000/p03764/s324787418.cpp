#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <numeric>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>


using namespace std;
using ll = long long;
const ll INF = 1e9;


int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> x(n+1), y(m+1);
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> y[i];
    }

    ll v = 0;
    for (int i = 1; i <= n; i++) {
        v += (i + i - n - 1) * x[i];
        v %= (ll)1e9 + 7;
    }

    ll d = 0;
    for (int i = 1; i <= m; i++) {
        d += (i + i - m - 1) * y[i];
        d %= (ll)1e9 + 7;
    }

    cout << (v * d) % ((ll)1e9 + 7) << endl;

    return 0;
}