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
#define _ << " " <<
#define all(X) (X).begin(), (X).end()
#define len(X) (X).size()
#define Pii pair<int, int>
#define Pll pair<ll, ll>
#define Tiii tuple<int, int, int>
#define Tlll tuple<ll, ll, ll>

int main() {
    ll n, s = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s += a[i];
    }

    if (s % (n * (n + 1) / 2)) {
        cout << "NO" << endl;
        return 0;
    }
    ll op = s / (n * (n + 1) / 2), cnt = 0;
    vector<int> b(n, 0);
    for (int i = 0; i < n; i++) {
        ll d = a[(i + 1) % n] - a[i];
        //cerr << op _ d << endl;
        if ((op - d) % n || (op - d) / n < 0) {
            cout << "NO" << endl;
            return 0;
        }
        cnt += (op - d) / n;
        b[i] = (op - d) / n;
    }
    //cerr << cnt _ op << endl;
    cout << (cnt == op ? "YES" : "NO") << endl;
}
