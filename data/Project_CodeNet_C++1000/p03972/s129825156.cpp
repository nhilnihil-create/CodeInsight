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
    ll a, b;
    cin >> a >> b;
    ll ans = 0;
    vector<ll> p(a), q(b);
    for (int i = 0; i < a; i++) {
        cin >> p[i];
        ans += p[i];
    }
    for (int i = 0; i < b; i++) {
        cin >> q[i];
        ans += q[i];
    }
    sort(all(q));
    vector<ll> s(b + 1, 0);
    for (int i = 0; i < b; i++) s[i + 1] = s[i] + q[i];

    for (int i = 0; i < a; i++) {
        int l = -1, r = b;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (q[m] > p[i]) r = m;
            else l = m;
        }
        ans += s[l + 1] + (b - l - 1) * p[i];
        //cerr << "l: " << l << endl;
    }
    cout << ans << endl;



}
