//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;

int main() {
    int n;
    cin >> n;
    ll k;
    cin >> k;
    vector<P> vv(n);
    rep(i, n) {
        int a, b;
        cin >> a >> b;
        vv[i] = P(a, b);
    }

    sort(all(vv));
    ll sum = 0;
    rep(i, n) {
        sum += vv[i].second;
        if(sum >= k) {
            cout << vv[i].first << endl;
            return 0;
        }
    }
}