#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
#include <cassert>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
using namespace std;
using ll = long long;
constexpr ll INF = 3000000000000000000;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    REP(i, n) {
        cin >> a[i];
        sum += a[i];
    }
    
    if (n == 1) {
        cout << "YES\n";
        return 0;
    }
    if (sum % ((n + 1) * n / 2)) {
        cout << "NO\n";
        return 0;
    }
    ll k = sum / ((n + 1) * n / 2);
    a.push_back(a[0]);
    vector<ll> vec(n, 0);
    REP(i, n) {
        ll x = k - (a[i + 1] - a[i]);
        if (x % n) {
            cout << "NO\n";
            return 0;
        }
        vec[i] = x / n;
    }
    
    bool judge = true;
    REP(i, n) {
        if (vec[i] < 0 || vec[i] > k) judge = false;
    }
    if (!judge) {
        cout << "NO\n";
        return 0;
    }
    ll s = 0;
    REP(i, n) s += vec[i];
    if (s > k) {
        cout << "NO\n";
    } else {
        if ((k - s) % n) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
    return 0;
}
