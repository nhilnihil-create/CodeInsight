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

bool comp(const P x, const P y){
    return x.second < y.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<P> a(n);
    rep(i, n) {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(all(a));
    rep(i, n) {
        a[i].first = i;
    }

    sort(all(a), comp);

    int ans = 0;
    rep(i, n/2) {
        if(a[i*2+1].first%2 == 0) {
            ans++;
        }
    }

    cout << ans << endl;
}