#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <queue>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define ALL(a) (a).begin(), (a).end()
#define rALL(a) (a).rbegin(), (a).rend()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int iINF = 1001001001;
const long long llINF = 1LL << 60;
ll getGCD(ll a, ll b)
{
    // Greatest Common Divisor
    if (b == 0)	return a;
    return getGCD(b, a % b);
}
int main()
{
    // AGC018-A, 1168, 
    int n, k; cin >> n >> k;
    vector<int> a(n);
    bool isFoundOdd = false;
    rep(i, n) {
        cin >> a[i];
        if (a[i] % 2 == 1) isFoundOdd = true;
    }
    if (n == 1 && k != a[0]) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    else if (n == 1) {
        cout << "POSSIBLE" << endl;
        return 0;
    }
    sort(ALL(a));
    if (a.back() < k) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    if (!isFoundOdd && k % 2 == 1) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    ll gcd = llINF;
    rep(i, n - 1) {
        gcd = min(gcd, getGCD(a[i], a[i + 1]));
    }
    if (k % gcd != 0) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    cout << "POSSIBLE" << endl;

    return 0;
}