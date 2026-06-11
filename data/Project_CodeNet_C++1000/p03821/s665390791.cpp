//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using ld = long double;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    ll aa = 0;
    rep(i, n) {
        cin >> a[i] >> b[i];
    }

    reverse(all(a));
    reverse(all(b));

    rep(i, n) {
        int num = ((a[i]+aa+b[i]-1)/b[i])*b[i]-a[i]-aa;
        aa += num;
    }

    cout << aa << endl;
}