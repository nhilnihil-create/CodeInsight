#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <tuple>
#include <cstring>
#include <map>
#include <iomanip>
#include <ctime>
#include <complex>
#include <cassert>
#include <climits>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define _ << " " <<
#define all(X) (X).begin(), (X).end()
#define len(X) (X).size()
#define Pii pair<int, int>
#define Pll pair<ll, ll>
#define Tiii tuple<int, int, int>
#define Tlll tuple<ll, ll, ll>

int main() {
    ll n;
    cin >> n;
    vector<ll> a(3*n);
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> large;

    vector<ll> p(3*n), q(3*n);
    ll sm = 0;
    for (int i = 0; i < 3*n; i++) {
        cin >> a[i];
        if (i < n) {
            large.push(a[i]);
            sm += a[i];
        }
    }
    p[n] = sm;
    for (int i = n; i < 2*n; i++) {
        ll kth = large.top();
        if (kth < a[i]) {
            large.pop();
            large.push(a[i]);
            sm += a[i] - kth;
        }
        p[i + 1] = sm;
    }
    reverse(all(a));
    sm = 0;
    for (int i = 0; i < n; i++) {
        small.push(a[i]);
        sm += a[i];
    }
    q[n] = sm;
    for (int i = n; i < 2*n; i++) {
        ll kth = small.top();
        if (kth > a[i]) {
            small.pop();
            small.push(a[i]);
            sm += a[i] - kth;
        }
        q[i + 1] = sm;
    }

    ll ans = -1e18;
    for (int i = n; i <= 2*n; i++) {
        ans = max(ans, p[i] - q[3*n - i]);
    }
    cout << ans << endl;

    /*for (int i = n; i <= 2*n; i++) {
        cerr << i _ p[i] _ q[3*n-i] << endl;
    }*/

}
