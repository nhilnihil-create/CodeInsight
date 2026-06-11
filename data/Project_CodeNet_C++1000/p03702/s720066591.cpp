#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <limits>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <bitset>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const int dx[] = {1, 0, -1, 0, 0};
const int dy[] = {0, 1, 0, -1, 0};

const int Maxn = 100010;
const int MOD = (int) 1e9 + 7;

int n;
ll a, b;
ll h[Maxn];

bool C(ll k) {
    ll cnt = 0;
    for (int i = 0; i < n; ++i) {
        ll rest = h[i] - k * b;
        if (rest > 0) cnt += (rest + a - b - 1) / (a - b);
    }
    return cnt <= k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> a >> b;
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    ll ok = (ll) 1e10, ng = 0, mid;
    while (ok - ng > 1) {
        mid = (ok + ng) / 2;
        if (C(mid)) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
}
