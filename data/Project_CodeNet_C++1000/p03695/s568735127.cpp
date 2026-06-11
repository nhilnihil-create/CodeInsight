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
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vi color(9);
    rep(i, n) {
        int a;
        cin >> a;
        if(a >= 3200) {
            color[8]++;
        } else {
            color[a/400]++;
        }
    }
    int cnt = 0;
    rep(i, 8) {
        cnt += color[i] != 0;
    }
    cout << max(1, cnt) << ' ' << cnt+color[8] << endl;
}