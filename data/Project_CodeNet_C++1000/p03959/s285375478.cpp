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
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    vector<ll> c(n, 0);
    c[0] = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i - 1] < a[i]) {
            c[i] = a[i];
        }
    }
    for (int i = 0; i < n; i++) cerr << c[i] << " ";
    cerr << endl;
    if (c[n - 1] != 0 && c[n - 1] != b[n - 1]) {
        cout << 0 << endl;
        return 0;
    }
    else c[n - 1] = b[n - 1];
    for (int i = 0; i < n - 1; i++) {
        if (b[i] > b[i + 1]) {
            if (c[i] == 0) c[i] = b[i];
            else if (c[i] != b[i]) {
                cout << 0 << endl;
                return 0;
            }
        }
        else {
            if (c[i] != 0 && c[i] > b[i]) {
                cout << 0 << endl;
                return 0;
            }
        }
    }
    for (int i = 0; i < n; i++) cerr << c[i] << " ";
    cerr << endl;

    ll ans = 1, mod = 1e9 + 7;
    for (int i = 0; i < n; i++) {
        if (c[i] == 0) ans = ans * min(a[i], b[i]) % mod;
    }
    cout << ans << endl;
    
}
