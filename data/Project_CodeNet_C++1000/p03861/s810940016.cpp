#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <list>
#include <iomanip>
#include <queue>
#include <cmath>
#include <numeric>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)

using namespace std;
using ll = long long;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
const long long mod = 1e9 + 7;
ll dx[] = { 1,0 };
ll dy[] = { 0,1 };

int main() {

    ll a, b, x;
    cin >> a >> b >> x;

    ll cnt1, cnt2;
    if (a == 0) {
        cnt1 = -1;
    }
    else    
    {
        cnt1 = (a - 1) / x;
    }

    cnt2 = b / x;

    cout << cnt2 - cnt1;

    return 0;
}